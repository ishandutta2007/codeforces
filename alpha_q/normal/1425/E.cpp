#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define un(x)           x.erase(unique(all(x)), x.end())
#define xx              first
#define yy              second
#define pb              push_back
#define all(v)          v.begin(), v.end()

#define D(x)            cerr << #x " = " << x << '\n'
#define DBG             cerr << "Hi!" << '\n'

#define CLR(a)          memset(a, 0, sizeof(a))
#define SET(a)          memset(a, -1, sizeof(a))

// inline int setBit(int n, int pos) { return n = n | (1 << pos); }
// inline int resetBit(int n, int pos) { return n = n & ~(1 << pos); }
// inline bool checkBit(int n, int pos) { return (bool)(n & (1 << pos)); }

// int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
// int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// unsigned int num = rng();
// shuffle(V.begin(), V.end(), rng);

/******************************************************************************************/

const int MAX = 100010;
// const int INF = 0x3f3f3f3f;
// const int MOD = 998244353;

// inline int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
// inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
// inline int mul(int a, int b) { return (a * 1LL * b) % MOD; }


ll a[MAX], d[MAX], c[MAX], mn[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // freopen("in", "r", stdin); 
    // freopen("out", "w", stdout);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[i] = c[i - 1] + a[i];
    }
    mn[0] = 1e9;
    for(int i = 1; i <= n; ++i) {
        cin >> d[i];
        mn[i] = min(mn[i - 1], d[i]);
    }
    if(k == 0) {
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = max(ans, c[n] - c[i - 1] - d[i]);
        }
        cout << ans << endl;
    }
    else if(k == 1) {
        ll ans = 0;
        
        int id = -1;
        ll least = 1e9;
        for(int i = 2; i <= n - 1; ++i) {
            least = min(least, a[i]);
            if(a[i] == least) {
                id = i;
            }
        }
            
        ans = max(ans, c[n] - d[1] - least);

        for(int i = 2; i <= n; ++i) {
            ans = max(ans, c[n] - c[i - 1] - d[i]);
        }

        for(int i = n - 1; i >= 1; --i) {
            ll cur = max(0LL, c[n] - c[i] - d[i + 1]) + c[i] - mn[i];
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    else {
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = max(ans, c[n] - c[i - 1] - d[i]);
        }
        for(int i = n - 1; i >= 1; --i) {
            ll cur = max(0LL, c[n] - c[i] - d[i + 1]) + c[i] - mn[i];
            ans = max(ans, cur);
        }
        
        ll least = 1e9;
        for(int i = 1; i < n; ++i) least = min(least, d[i]);
        ans = max(ans, c[n] - least);


        cout << ans << endl;
    }
    return 0;
}