#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const ll MAX = 1e18;
vector<pair<char, pll>> ans;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

ll sum(ll x, ll y)
{
    ans.push_back({'+',{x, y}});
    return x+y;
}
ll x0r(ll x, ll y)
{
    ans.push_back({'^',{x, y}});
    return x^y;
}
ll mul(ll x, ll y)
{
    ll ans = 0;
    for(; y; x = sum(x,x), y >>= 1)
        if(y & 1)
            if(ans == 0)
                ans = x;
            else
                ans = sum(ans, x);
    return ans;
}

void test(ll zz)
{
    ll x = zz;
    ll y = x;
    cerr << "Input: " << x << '\n';
    while(gcd(x, y) > 1)
    {
        ll tmp = y;
        y = sum(y,y);
        y = x0r(y,tmp);
    }
    cerr << "Coprime: " << y << '\n';
    x = sum(x,x);
    ll z = modDivide(1, y, x);
    cerr << "Mod Inverse: " << z << '\n';
    z = mul(y, z);
    cerr << "Mod unit: " << z << '\n';
    y = x;
    y = mul(y, (z-1)/y);
    x0r(y, z);
    cerr << "# of Ops: " << ans.size() << '\n';
}

int main()
{
    FAST;
    ll x;
    cin >> x;
    test(x);
    cout << ans.size() << '\n';
    for(auto P : ans)
        cout << P.S.F << ' ' << P.F << ' ' << P.S.S << '\n';
}