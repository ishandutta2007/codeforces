#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int mod = 998244353;
const int N = 300'010;
ll a[N];
int n;

const int my_lib_N = N;
const int my_lib_mod = mod;
ll mod_div(ll x, ll y, ll mod = my_lib_mod)
{
	if (x % y == 0)
		return x / y;
	return ((mod_div(y - x % y, mod % y, y) * mod + x) / y) % mod;
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
    FAST;
    cin >> n; //n * =2;
    Loop(i,0,2*n)
        cin >> a[i];
    sort(a, a+2*n);
    ll sum = 0;
    Loop(i,0,n)
        sum -= a[i], sum %= mod;
    Loop(i,n,2*n)
        sum += a[i], sum %= mod;
    calc_fact();
    sum *= C(2*n, n); sum %= mod;
    sum += mod; sum %= mod;
    cout << sum << '\n';
}