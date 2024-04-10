#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 210;
int A[N][N];
int ans[N][N];
int n, m;

void floyd()
{
    Loop(i,0,n) Loop(j,0,n) ans[i][j] = (A[i][j]? A[i][j] : 1e9);
    Loop(i,0,n) ans[i][i] = 0;
    Loop(k,0,n)
        Loop(i,0,n)
            Loop(j,0,n)
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
}

bool check_odd(int u=0, int c = 1)
{
    static int color[N] = {};
    color[u] = c;
    Loop(v,0,n)
    {
        if(!A[u][v]) continue;
        if(color[v] == c) return 1;
        if(color[v]) continue;
        if(check_odd(v, 3-c)) return 1;
    }
    return 0;
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        A[u][v] = 1;
        if(b) A[v][u] = -1;
        else  A[v][u] = 1;
    }
    if(check_odd()) Kill("NO");
    floyd();
    Loop(i,0,n)
        if(ans[i][i] != 0)
            Kill("NO");
    int mx = -1;
    int mxi = 0;
    int off = 0;
    Loop(i,0,n)
    {
        int cmx = 0, cmn = 0;
        Loop(j,0,n)
        {
            cmx = max(ans[i][j], cmx);
            cmn = min(ans[i][j], cmn);
        }
        if(cmx - cmn > mx)
        {
            mx = cmx - cmn;
            mxi = i;
            off = -cmn;
        }
    }
    cout << "YES\n" << mx << '\n';
    Loop(i,0,n)
        cout << ans[mxi][i] + off << ' ';
}