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

const int N = 310;
set<int> divs;
vector<int> divsv;
map<int, int> rev;
int l[N], c[N];
int n;
vector<ll> dp[N];
const ll inf = 1'000'000'000'000'010LL;

int gcd(int a, int b){return b==0? a: gcd(b, a%b);}

void div(int x)
{
    for(int y = 1; y*y <= x; ++y)
    {
        if(x%y)
            continue;
        divs.insert(y);
        divs.insert(x/y);
    }
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> l[i], div(l[i]);
    Loop(i,0,n)
        cin >> c[i];
    int k = 0;
    for(int x : divs)
        rev[x] = k++,
        divsv.push_back(x);
    dp[0].resize(k+1, inf);;
    Loop(i,0,n)
    {
        dp[i+1].resize(k+1, inf);
        Loop(j,0,k+1)
        {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j)
            {
                int r = rev[gcd(divsv[j-1], l[i])];
                dp[i+1][r+1] = min(dp[i+1][r+1], dp[i][j] + c[i]);
            }
            else
            {
                dp[i+1][rev[l[i]]+1] = min(dp[i+1][rev[l[i]]+1], (ll)c[i]);
            }
        }
    }
    cout << (dp[n][1]==inf?-1:dp[n][1]) << '\n';
}