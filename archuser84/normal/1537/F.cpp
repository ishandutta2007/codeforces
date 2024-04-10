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

const int N = 200'010;
vector<int> *A;
ll a[N];
int n, m;

int c[N];
bool dfs(int v, int c = 1)
{
    ::c[v] = c;
    for(int u : A[v])
        if(!::c[u])
            {if(!dfs(u, 3-c)) return 0;}
        else if(::c[u] == c)
            {return 0;}
    return 1;
}

bool solve()
{
    cin >> n >> m;
    A = new vector<int>[n];
    Loop(i,0,n) cin >> a[i];
    Loop(i,0,n) {ll x; cin >> x; a[i] -= x;}
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    {
        ll sum = 0;
        Loop(i,0,n) sum += a[i];
        if(sum&1) return 0;
    }
    memset(c, 0, 4*n);
    if(!dfs(0)) return 1;
    {
        ll sum = 0;
        Loop(i,0,n)
            sum += a[i]*(2*c[i]-3);
        return !sum;
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        cout << YN(solve()) << '\n';
}