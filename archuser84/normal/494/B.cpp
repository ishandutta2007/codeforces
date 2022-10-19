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

const int N = 300'010;
string s;
int f[N];
void kmp()
{
    f[0] = -1;
    Loop(i,1,s.size()+1)
    {
        int t = f[i-1];
        while(t >= 0 && s[t] != s[i-1])
            t = f[t];
        f[i] = t+1;
    }
}

const int mod = 1'000'000'007;
string a, b;
ll dp[N] = {};
ll* par = new ll[N]{};

int main()
{
    FAST;
    cin >> a >> b;
    int n = b.size(), m = a.size();
    s = b + "#" + a;
    kmp();
    dp[0] = 1;
    par[0] = 0; ++par; par[0] = 1;
    int l = 0;
    Loop(i, 1, m+1)
    {
        if(f[i+n+1] == n)
            l = i-n+1;
        dp[i] = (dp[i-1] + par[l-1]) % mod;
        par[i] = par[i-1] + dp[i];
    }
    cout << (dp[m]+mod-1)%mod << '\n';
}