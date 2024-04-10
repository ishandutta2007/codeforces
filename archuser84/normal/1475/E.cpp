#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int my_lib_N = 200'010;
const int my_lib_mod = 1'000'000'007;
ll mod_pow(ll x, ll e, int mod = my_lib_mod) {
    ll ans = 1;
    for(; e; e >>= 1)
    {
        if(e&1)
            ans = ans*x % mod;
        x = x*x % mod;
    }
    return ans;
}
ll mod_div(ll x, ll y, int mod = my_lib_mod) {
    return x * mod_pow(y,mod-2,mod) % mod;
}
ll fact[my_lib_N];
void calc_fact(int mod = my_lib_mod) {
    fact[0] = 1;
    Loop(i,1,my_lib_N)
        fact[i] = fact[i-1]*i % mod;
}
ll C(int n, int r, int mod = my_lib_mod) {
    return mod_div(fact[n], fact[r]*fact[n-r]%mod, mod);
}

int main()
{
    calc_fact();
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> a;
        int n, k;
        cin >> n >> k;
        while(n--)
        {
            int x;
            cin >> x;
            a.push_back(-x);
        }
        sort(all(a));
        int x = a[k-1];
        int k2 = lower_bound(all(a), x) - a.begin();
        cout << C(upper_bound(all(a), x) - lower_bound(all(a), x), k-k2) << '\n';
    }
}