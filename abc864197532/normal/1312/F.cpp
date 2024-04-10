#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

int mex(vector <int> a) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i = 0; i < a.size(); ++i) {
        if (i != a[i]) return i;
    }
    return a.size();
}

void solve () {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector <vector <int> > dp; // 0 - x, 1 - y, 2 - z
	dp.pb(vector <int> (3, 0));
	map <vector <vector <int>>, int> m1;
	m1[{dp[0]}] = 0;
	int pre, cycle;
	fop (i,1,60) {
		dp.pb(vector <int> (3, 0));
		fop (j,0,3) {
			vector <int> v;
			if (j == 0) {
				v.pb(dp[max(i - x, 0)][0]);
				v.pb(dp[max(i - y, 0)][1]);
				v.pb(dp[max(i - z, 0)][2]);
			} else if (j == 1) {
				v.pb(dp[max(i - x, 0)][0]);
				v.pb(dp[max(i - z, 0)][2]);
			} else {
				v.pb(dp[max(i - x, 0)][0]);
				v.pb(dp[max(i - y, 0)][1]);
			}
			dp.back()[j] = mex(v);
		}
		vector <vector <int>> v;
		fop (j,max(0, i - 4), i + 1) v.pb(dp[j]);
		if (m1.count(v)) {
			pre = m1[v];
			cycle = i - m1[v];
			break;
		} else {
			m1[v] = i;
		}
	}
	auto f = [=](lli a) {
		return a < pre ? a : (a - pre) % cycle + pre;
	};
	int all = 0;
	lli input[n];
	fop (i,0,n) {
		cin >> input[i];
		all ^= dp[f(input[i])][0];
	}
	int ans = 0;
	fop (i,0,n) {
		all ^= dp[f(input[i])][0];
		if ((all ^ dp[f(max(input[i] - x, 0ll))][0]) == 0) ans++;
		if ((all ^ dp[f(max(input[i] - y, 0ll))][1]) == 0) ans++;
		if ((all ^ dp[f(max(input[i] - z, 0ll))][2]) == 0) ans++;
		all ^= dp[f(input[i])][0];
	}
	cout << ans << '\n';
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}