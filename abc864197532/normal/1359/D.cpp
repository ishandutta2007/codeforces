#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 1000001, logN = 17;

int main () {
	int n;
	cin >> n;
	int a[n], pre[n + 1];
	fop (i,0,n) cin >> a[i];
	pre[0] = 0;
	fop (i,0,n) pre[i + 1] = pre[i] + a[i];
	/*
	pre[r] - pre[l] - mx[l..r]
	 = pre[r] + (pre[l] + mx[l..r])
	*/
	vector <bool> aa(n, false); 
	int ans = 0;
	fop (i,-30,31) {
		fop (j,0,n) if (a[j] == i) aa[j] = true;
		int now_min = 864197532;
		vector <int> tmp;
		fop (j,0,n + 1) {
			if (j and a[j - 1] == i) {
				bool is = true;
				while (tmp.size()) {
					int k = tmp.back(); tmp.pop_back();
					if (a[k] > i) {
						is = false;
					}
					if (!is) {
						while (tmp.size()) tmp.pop_back();
					} else {
						now_min = min(now_min, pre[k]);
					}
				}
 			}
			tmp.pb(j);
			if (a[j - 1] > i) {
				now_min = 864197532;
			}
			ans = max(ans, pre[j] - now_min - i);
		}
	}
	cout << ans << endl;
}