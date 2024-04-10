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
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 200'010;
const int lgN = 100;
ll fib[lgN];
int n;

bool vise[N] = {};
vector<pii> A[N];

int cnt[N];
int par[N];

vector<int> V;
int dfs(int u, int p, int pe)
{
    V.push_back(u);
    par[u] = pe;
    cnt[u] = 1;
    for(auto e : A[u])
        if(e.F != p && !vise[e.S])
            cnt[u] += dfs(e.F, u, e.S);
    return cnt[u];
}

bool ok(int s, int f)
{
    V.clear();
    dfs(s, -1, -1);
    if(cnt[s] <= 3) return 1;
    for(int v : V)
    {
        if(cnt[v] == fib[f-1])
        {
            vise[par[v]] = 1;
            return ok(v, f-1) && ok(s, f-2);
        }
        if(cnt[v] == fib[f-2])
        {
            vise[par[v]] = 1;
            return ok(v, f-2) && ok(s, f-1);
        }
    }
    return 0;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        A[u].emplace_back(v, i);
        A[v].emplace_back(u, i);
    }
    if(n <= 3) Kill("YES");
    fib[0] = fib[1] = 1;
    Loop(i,2,lgN) fib[i] = fib[i-1] + fib[i-2];
    Loop(i,2,lgN)
    {
        if(fib[i] > n) Kill("NO");
        if(fib[i] == n) Kill(YN(ok(0, i)));
    }
}