#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500005, logN = 18, K = 600, C = 100, M = 1e9;

struct BIT {
    long long val[N];
    void init() {
        for (int i = 0; i < N; ++i) {
            val[i] = 0;
        }
    }
    void add(int p, int v, bool is = true) {
        for (int i = p; i < N; i += i & (-i)) val[i] += v;
    }
    long long query(int p) {
        long long ans = 0;
        for (int i = p; i > 0; i -= i & (-i)) ans += val[i];
        return ans;
    }
} bit1, bit2;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    lli ans = 0;
    fop (i,0,n) {
        cin >> a[i];
        ans = (ans + 1ll * (i + 1) * (n - i) % mod * a[i]) % mod;
    }
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return a[i] < a[j];
    });
    /*
     * (mn + 1) * (n - mx)
     */
    fop (i,0,n) {
        int j = p[i];
        ans = (ans + bit1.query(j + 1) % mod * (n - j) % mod * a[j]) % mod;
        ans = (ans + bit2.query(j + 1) % mod * (j + 1) % mod * a[j]) % mod;
        bit1.add(j + 1, j + 1);
        bit2.add(1, n - j);
        bit2.add(j + 1, j - n);
    }
    cout << ans << endl;
}