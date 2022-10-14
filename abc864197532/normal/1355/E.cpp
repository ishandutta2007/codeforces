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
const int mod = 1e9 + 7, x = 864197532, N = 5001, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

long long modpow(int a, int b) {
	long long ans = 1;
	for (long long aa = a; b; b >>= 1, aa = aa * aa % mod) {
		if (b & 1) ans = ans * aa % mod;
	}
	return ans;
}

long long modinv (int b) {
	return modpow(b, mod - 2);
}

int main () {
    int n, a, r, m;
    cin >> n >> a >> r >> m;
    vector <lli> h(n);
    fop (i,0,n) cin >> h[i];
    auto f = [&](int x) {
        lli aa = 0, bb = 0;
        fop (i,0,n) {
            if (h[i] >= x) aa += h[i] - x;
            else bb += x - h[i];
        }
        if (m < a + r) {
            lli mm = min(aa, bb);
            return mm * m + (bb - mm) * a + (aa - mm) * r;
        } else {
            return aa * r + bb * a;
        }
    };
    auto df = [&](int x) {
        return f(x + 1) - f(x);
    };
    int l = 0, rr = 1e9 + 87;
    while (rr - l > 1) {
        (df(l + rr >> 1) > 0 ? rr : l) = l + rr >> 1;
    }
    cout << min(f(l), f(rr)) << endl;
}