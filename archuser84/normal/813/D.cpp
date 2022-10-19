///
///    I have a dream and a piano
///

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

const int N = 5010;
vector<int> stb;
int bts[100'010];
int dp0[N];
int dp1[N][N];
int dp2[N][N];
int dp3[N][7];
int a[N];
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> a[i], stb.push_back(a[i]);
    sort(all(stb));
    stb.resize(unique(all(stb))-stb.begin());
    memset(bts, -1, sizeof bts);
    Loop(i,0,stb.size()) bts[stb[i]] = i;
    dp1[0][1] = dp1[1][0] = 2;
    dp2[0][bts[a[1]]] = dp2[1][bts[a[0]]] = 2;
    dp3[0][a[1]%7] = dp3[1][a[0]%7] = 2;
    Loop(j,0,n) {dp0[j]=1; Loop(i,0,j) if(a[i]%7==a[j]%7 || a[i]+1==a[j] || a[i]-1==a[j]) dp0[j] = max(dp0[j], 1+dp0[i]);}
    Loop(j,2,n)
    {
        Loop(i,0,j) dp1[i][j] = 1+max({dp3[i][a[j]%7],bts[a[j]-1]==-1?0:dp2[i][bts[a[j]-1]],bts[a[j]+1]==-1?0:dp2[i][bts[a[j]+1]],dp0[i]});
        Loop(i,0,j){
            dp1[j][i] = dp1[i][j];
            dp2[i][bts[a[j]]] = max(dp2[i][bts[a[j]]], dp1[i][j]);
            dp2[j][bts[a[i]]] = max(dp2[j][bts[a[i]]], dp1[i][j]);
            dp3[i][a[j]%7] = max(dp3[i][a[j]%7], dp1[i][j]);
            dp3[j][a[i]%7] = max(dp3[j][a[i]%7], dp1[i][j]);
        }
    }
    int ans = 0;
    Loop(i,0,n) Loop(j,i+1,n) ans = max(ans, dp1[i][j]);
    cout << ans << '\n';
}