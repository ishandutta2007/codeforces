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
#define X first
#define Y second
vector <pair <string, int>> ans;
int now = 0, k;

void printt() {
	ans.back().Y -= (now - k);
	int kk = ans.size();
	for (auto i : ans) {
		if (i.Y == 0) kk--;
	}
	cout << "YES" << endl;
	cout << kk << endl;
	for (auto i : ans) {
		if (i.Y != 0) cout << i.Y << ' ' << i.X << endl;
	}
}



int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m >> k;
	if (4 * n * m - 2 * n - 2 * m < k) {
		cout << "NO" << endl;
		return 0;
	}
	fop (i,0,m-1) {
		ans.pb({"D", n - 1});
		now += n - 1;
		if (now >= k) break;
		ans.pb({"U", n - 1});
		now += n - 1;
		if (now >= k) break;
		ans.pb({"R", 1});
		now++;
		if (now >= k) break;
	}
	if (now >= k) {
		printt();
		return 0;
	}
	fop (i,0,n-1) {
		ans.pb({"D", 1});
		now++;
		if (now >= k) break;
		ans.pb({"L", m - 1});
		now += m - 1;
		if (now >= k) break;
		ans.pb({"R", m - 1});
		now += m - 1;
		if (now >= k) break;
	}
	if (now >= k) {
		printt();
		return 0;
	}
	ans.pb({"U", n - 1});
	now += n - 1;
	if (now >= k) {
		printt();
		return 0;
	}
	ans.pb({"L", m - 1});
	now += m - 1;
	printt();
	return 0;
}