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

// const int MAX = 500010;
// const int INF = 0x3f3f3f3f;
// const int MOD = 998244353;

// inline int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
// inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
// inline int mul(int a, int b) { return (a * 1LL * b) % MOD; }


ll dp[1000000];

ll call(ll n) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    dp[n] = 1 + (n - 1) - call(n - 1);
    if(n % 2 == 0) {
        dp[n] = max(dp[n], n - call(n / 2));
    }
    return dp[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // freopen("in", "r", stdin); 
    // freopen("out", "w", stdout);

    SET(dp);
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {   
        ll n;
        cin >> n;
        ll a[2] = {0, 0};
        int turn = 0;
        while(n) {
            if(n <= 12) {
                a[turn] += call(n);
                a[turn ^ 1] += n - call(n);
                n = 0;
            }
            else if(n & 1LL) {
                a[turn]++;
                n--;
            }
            else {
                if((n / 2) & 1LL) {
                    a[turn] += n / 2;
                    n /= 2;
                }
                else {
                    a[turn]++;
                    n--;       
                }
            }
            turn ^= 1;
        }
        cout << a[0] << '\n';
    }
    return 0;
}