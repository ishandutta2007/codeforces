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
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    odd:
    First
    even:
    n = 2^a * b
    a > 1 : First
    else : Second
    */
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int cnt = 0;
    	while (n % 2 == 0) cnt++, n /= 2;
    	if (n == 1) {
    		if (cnt != 1) {
    			cout << "FastestFinger\n";
			} else {
				cout << "Ashishgup\n";
			}
		} else {
			bool is = true;
			for (int i = 2; i * i <= n; ++i) {
				if (n % i == 0) is = false;
			}
			if (cnt == 1 && is) {
    			cout << "FastestFinger\n";
			} else {
				cout << "Ashishgup\n";
			}
		}
	}
}