///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

const int N = 2010;
int dp[N];
pii cnt[N];
int a[N], b[N];
int x, y;
int n;

inline pii operator+(pii a, pii b){return {a.F+b.F, a.S+b.S};}

void calc(int cst1, int cst2)
{
    dp[0] = 0;
    Loop(i,0,n)
    {
        dp[i+1] = max({dp[i], dp[i]+a[i]-cst1, dp[i]+b[i]-cst2, dp[i]+(10000-(10000-a[i])*(10000-b[i])/10000)-cst1-cst2});
        cnt[i+1] = {N,N};
        if(dp[i+1] == (dp[i]+(10000-(10000-a[i])*(10000-b[i])/10000)-cst1-cst2)) cnt[i+1] = cnt[i]+pii{1,1};
        if(dp[i+1] == (dp[i]+a[i]-cst1                                        )) cnt[i+1] = cnt[i]+pii{1,0};
        if(dp[i+1] == (dp[i]+b[i]-cst2                                        )) cnt[i+1] = cnt[i]+pii{0,1};
        if(dp[i+1] == (dp[i]                                                  )) cnt[i+1] = cnt[i]+pii{0,0};
    }
}

int main()
{
    FAST;
    cin >> n >> x >> y;
    Loop(i,0,n) {double f; cin >> f; a[i] = f*10000;}
    Loop(i,0,n) {double f; cin >> f; b[i] = f*10000;}
    int l1, l2, r1, r2;
    for(l2 = 0, r2 = 10000; l2 < r2;)
    {
        int m2 = (l2+r2)/2;
        for(l1 = 0, r1 = 10000; l1 < r1;)
        {
            int m1 = (l1+r1)/2;
            calc(m1, m2);
            if(cnt[n].F > x) l1 = m1+1;
            else             r1 = m1;
        }
        calc(l1, m2);
        if(cnt[n].S > y) l2 = m2+1;
        else             r2 = m2;
    }
    calc(l1, l2);
    cout << (dp[n]+l1*x+l2*y)/10000. << '\n';
}