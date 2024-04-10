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

const int N = 100'010;
vector<pii> A[N];
int n, k;

pll dfs(int u, int p)
{
    ll x=0, y=0;
    vector<pll> V;

    for(auto e : A[u])
        if(e.F != p){
            auto t = dfs(e.F, u);
            t.F += e.S, t.S += e.S;
            V.push_back(t);
        }

    sort(all(V)); reverse(all(V));
    Loop(i,0,min(k-1, (int)V.size())) x += V[i].F;
    y = x;
    Loop(j,k-1,V.size()) y = max(y, x + V[j].S);
    if(V.size() >= k) Loop(j,0,k-1) y = max(y, x - V[j].F + V[k-1].F + V[j].S);
    else              Loop(j,0,V.size()) y = max(y, x - V[j].F + V[j].S);
    return {x, y};
}

int main()
{
    FAST;
    cin >> n >> k;
    Loop(i,1,n)
    {
        int u, v, c;
        cin >> u >> v >> c;
        A[u].push_back({v, c});
        A[v].push_back({u, c});
    }
    cout << dfs(0, -1).S << '\n';
}