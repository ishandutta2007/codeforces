#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 200'010;
vector<int> A[N];
vector<int> T[N];
vector<pii> E;
int vv[N];
int vcnt[N];
int n, m;

bool bfs()
{
    //cout << '\n';
    int cnt = 0;
    queue<int> Q;
    Loop(i,0,n)
    {
        vcnt[i] = T[i].size();
        if(T[i].size() == 0)
        {
            vv[i] = ++cnt;
            Q.push(i);
        }
    }
    while(Q.size())
    {
        int u = Q.front();
        Q.pop();
        for(int v : A[u])
            if(--vcnt[v] == 0)
            {
                Q.push(v);
                vv[v] = ++cnt;
            }
    }
    //cout << '\n';
    return cnt == n;
}

int solve()
{
    cin >> n >> m;

    Loop(i,0,n)
        A[i].clear(),
        T[i].clear();
    E.clear();

    Loop(i,0,m)
    {
        int t, u, v;
        cin >> t >> u >> v;
        u--; v--;
        if(!t)
            E.push_back({u, v});
        else
            A[u].push_back(v),
            T[v].push_back(u);
    }

    if(!bfs())
        Kill("NO");

    cout << "YES\n";
    for(auto e : E)
    {
        if(vv[e.F] < vv[e.S])
            cout << e.F+1 << ' ' << e.S+1 << '\n';
        else
            cout << e.S+1 << ' ' << e.F+1 << '\n';
    }
    Loop(u,0,n)
        for(int v : A[u])
            cout << u+1 << ' ' << v+1 << '\n';
    return 0;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}