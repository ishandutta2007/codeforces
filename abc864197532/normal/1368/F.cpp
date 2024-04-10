#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 998244353, x = 864197532, N = 300000, logN = 17;

int main () {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    if (n <= 3) {
    	cout << 0 << endl;
    	return 0;
	}
    int k = 2;
    fop (i,3,n + 1) {
    	int cur = n - ((n + k - 1) / k) - (k - 1);
    	if (cur < n - ((n + i - 1) / i) - (i - 1)) k = i;
	}
	int all = n - ((n + k - 1) / k) - (k - 1);
    vector <int> need;
    // OOXOOXOOXOX
    fop (i,0,n - 1) {
    	if (i % k < k - 1) {
    		need.pb(i);
		}
	}
    vector <bool> is(n, false);
    int x;
    fop (i,0,k - 1) {
    	cout << k;
    	fop (j,0,k) cout << ' ' << j * k + i + 1, is[j * k + i] = true;
    	cout << endl;
    	cin >> x;
    	for (int i = x - 1, cnt = 0; cnt < k; i = (i + 1) % n) {
    		is[i] = false;
    		cnt++;
		}
	}
	while (accumulate(all(is), 0) < all) {
		cout << k;
		int cnt = 0;
		for (int i = 0, cnt = 0; cnt < k && i < need.size(); ++i) {
			if (!is[need[i]]) {
				cout << ' ' << need[i] + 1;
				is[need[i]] = true;
				cnt++;
			}
		}
		cout << endl;
		cin >> x;
		for (int i = x - 1, cnt = 0; cnt < k; i = (i + 1) % n) {
    		is[i] = false;
    		cnt++;
		}
	}
	cout << 0 << endl;
}