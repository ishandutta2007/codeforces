#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;


const ll MOD = 1000000007;

ll powmod(ll a, ll b)
{
    if (b == 0) {
        return 1;
    }
    ll r = powmod(a, b >> 1);
    (r *= r) %= MOD;
    return b & 1? r * a % MOD : r;
}

ll divmod(ll a, ll b)
{
    return a * powmod(b, MOD - 2) % MOD;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for (ll mod = 1; mod < b; ++mod) {
        ll st = (b * mod + mod) % MOD;
        (ans += (st + st + mod * b % MOD * (a - 1)) % MOD * a) %= MOD;
    }
    cout << divmod(ans, 2) << endl;
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}