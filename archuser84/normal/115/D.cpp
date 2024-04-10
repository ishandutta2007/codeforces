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

const int N = 2010;
const int mod = 1000003;
char s[N];
int nxt[N];

ll dp[N][N];

ll solve(int b, int e)
{
    if(dp[b][e] >= 0) return dp[b][e];
    if(b == e) return 0;
    dp[b][e] = 0;
    if(s[b] == '/' || s[b] == '*') return dp[b][e];
    bool seen = 0;
    if(s[b] == '+' || s[b] == '-') dp[b][e] = solve(b+1, e), seen = 1;
    for(int m = nxt[b]; m < e; m = nxt[m])
        dp[b][e] = (dp[b][e] + solve(b, m)*solve(m+1,e)) % mod,
            seen = 1;
    if(!seen)
        dp[b][e] = 1;
    return dp[b][e];
}

int main()
{
    FAST;
    cin >> s;
    int n = strlen(s);
    int l = n;
    LoopR(i,0,n) {
        nxt[i] = l;
        if((s[i] < '0' || s[i] > '9') && (s[i-1] >= '0' && s[i-1] <= '9'))
            l = i;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, n);
}