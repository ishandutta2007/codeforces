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
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
	fop (i,0,n) cin >> a[i];
    fop (i,0,n) cin >> b[i];
    bool is = true;
    // check for a < b
    /*
    (a + 1) * k < b
    b - a * k > k
    
    (b + 1) * k < a
    a - b * k > k
    */
    lli pre = 0;
    fop (i,0,n) {
    	pre += b[i] - 1ll * a[i] * k;
    	if (pre < 0) pre = 0;
    	if (pre > k) is = false; 
	}
	pre = 0;
    // check for b < a
    fop (i,0,n) {
    	pre += a[i] - 1ll * b[i] * k;
    	if (pre < 0) pre = 0;
    	if (pre > k) is = false;
	}
	cout << (is ? "YES\n" : "NO\n");
}