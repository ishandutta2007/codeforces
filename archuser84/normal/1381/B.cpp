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

const int N = 4010;

bool exist(int n, vector<int>& x)
{
    static bool dp[N][N];
    Loop(i,0,n+1) Loop(j,0,n+1) dp[i][j] = 0;
    dp[0][0] = 1;
    Loop(k,0,x.size())
    {
        Loop(s,0,n+1)
        {
            dp[k+1][s] = dp[k][s];
            if(x[k] <= s) dp[k+1][s] |= dp[k][s-x[k]];
        }
    }
    return dp[x.size()][n/2];
}

void solve()
{
    vector<int> a;
    vector<int> x;
    set<int, greater<int>> s;
    int n;
    cin >> n; n*=2;
    Loop(i,0,n) {int x; cin >> x; a.push_back(x); s.insert(i+1);}
    int r = n;
    LoopR(i,0,n)
    {
        if(a[i] == *s.begin()){
            x.push_back(r-i);
            //cerr << r-i << ' ';
            r = i;
        }
        s.erase(a[i]);
    }
    cout << YN(exist(n, x)) << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}