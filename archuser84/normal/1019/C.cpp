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

const int N = 1'000'010;
set<int> G;
set<int> ans;
vector<int> A[N], T[N];

void solve()
{
    if(G.empty()) return;
    int u = *G.begin();
    G.erase(u);
    for(int v : A[u]) G.erase(v);
    solve();
    bool flag = 0;
    for(int v : T[u]) if(ans.count(v)){flag = 1; break;}
    if(!flag) ans.insert(u);
}

int main()
{
    FAST;
    int n, m;
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        T[v].push_back(u);
    }
    Loop(i,0,n) G.insert(i);
    solve();
    cout << ans.size() << '\n';
    for(int u : ans)
        cout << u+1 << ' ';
}