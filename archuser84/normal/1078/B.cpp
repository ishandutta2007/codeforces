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


const int N = 102;
int dp1[N][N*N]={};
int dp2[N][N*N]={};
int a[N];
set<int> s;

int main()
{
    FAST;
    dp2[0][0] = 1;
    int n;
    cin >> n;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        a[x]++;
        s.insert(x);
    }
    if(s.size() <= 2) Kill(n);
    Loop(x,0,N)
        Loop(cnt,1,a[x]+1)
            dp1[cnt][cnt*x] = min(200, dp1[cnt][cnt*x]+1);
    Loop(x,0,N)
        LoopR(k,0,N)
            LoopR(m,0,N*N)
                for(int cnt = 1; k+cnt < N && m+x*cnt < N*N && cnt <= a[x]; ++cnt)
                    dp2[k+cnt][m+cnt*x] = min(200, dp2[k+cnt][m+cnt*x]+dp2[k][m]);
    LoopR(k,0,N)
        Loop(m,0,N*N)
            if(dp2[k][m] == 1 && dp1[k][m] == 1)
                Kill(k);
}