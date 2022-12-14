/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 2.5e5 + 10;
const ll MAXT = 220;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

template<ll Mod>
struct ModInt {
    ll val;

    ModInt() : val(0) {}
    template <class U> ModInt(const U& x){
        val = (-Mod < x && x < Mod) ? x : x % Mod;
        val = (val < 0) ? val + Mod : val;
    }

    friend ostream &operator<<(ostream &os, ModInt x) { return os << x.val;}
    friend istream &operator>>(istream &is, ModInt &x) { return is >> x.val;}

    friend ModInt operator+(ModInt x, ModInt y) { return ModInt(x.val + y.val);}
    friend ModInt operator-(ModInt x, ModInt y) { return ModInt(x.val - y.val);}
    friend ModInt operator*(ModInt x, ModInt y) { if (Mod > ll(2e9)) return x.LogMul(x, y); return ModInt(x.val * y.val);}
    friend ModInt operator/(ModInt x, ModInt y) { return x * x.inv(y); }
    friend ModInt operator^(ModInt x, ll y) {
        ModInt ans = 1;
        for(; y ; y /= 2 , x *= x)  if(y & 1)   ans *= x;
        return ans;
    }

    template<class T> ModInt operator+=(T x) { return (*this) = (*this) + x;}
    template<class T> ModInt operator-=(T x) { return (*this) = (*this) - x;}
    template<class T> ModInt operator*=(T x) { return (*this) = (*this) * x;}
    template<class T> ModInt operator/=(T x) { return (*this) = (*this) / x;}
    template<class T> ModInt operator^=(T x) { return (*this) = (*this) ^ x;}

    ModInt inv(ModInt x) { return ModInt(x.val) ^ (Mod - 2); }

    ModInt LogMul(ModInt x, ModInt y) {
        if (y.val == 1) return x;
        return LogMul(ModInt(2 * x.val), ModInt(y.val / 2)) + (y.val % 2 == 1 ? x.val : 0);
    }
};

template <ll T = MOD> using mll = ModInt<T>;

ll a , b , k , t;
mll<> dp[2][MAXN * 2];

int main() {
    fast_io;

    cin >> a >> b >> k >> t;
    dp[0][a - b + MAXN] = 1;

    for(ll i = 1 ; i <= 2 * t ; i++){
        for(ll j = 0 ; j < MAXN * 2 ; j++){
            if(dp[0][j].val == 0)   continue;
            dp[1][j - k] += dp[0][j];
            dp[1][j + k + 1] -= dp[0][j];
        }
        partial_sum(dp[1] , dp[1] + MAXN * 2 , dp[1]);
        for(ll j = 0 ; j < MAXN * 2 ; j++)  dp[0][j] = dp[1][j];
        fill(dp[1] , dp[1] + MAXN * 2 , mll<>(0));
    }
    cout << accumulate(dp[0] + MAXN + 1 , dp[0] + MAXN * 2 , mll<>(0)) << endl;

    return 0;
}
/*

*/