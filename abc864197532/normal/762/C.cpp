#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200087, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
	vector <int> pre(m + 1, -1);
	int now = 0, pree = 0, suff = 0;
    fop (i,1,m + 1) {
    	while (now < n && s[now] != t[i - 1]) now++;
    	pre[i] = now;
    	now = min(now + 1, n);
    	if (pre[i] < n) pree = i;
	}
	now = n - 1;
	FOP (i,m,0) {
		while (now >= 0 && s[now] != t[i]) now--;
		int pos = lower_bound(all(pre), now) - pre.begin() - 1;
		pos = min(pos, i);
		if (now != -1) {
			if (pos + m - i > pree + suff) {
				pree = pos;
				suff = m - i;
			}
		}
		now = max(now - 1, -1);
	}
	if (pree + suff == 0) cout << "-\n";
	else {
		cout << t.substr(0, pree) << t.substr(m - suff) << endl;
	}
}