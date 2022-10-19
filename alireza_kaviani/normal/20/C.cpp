#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}

const ll MAXN = 1e5 + 10 , INF = 1e18;
set<int> vet;
vector<pii> adj[MAXN];
ll dist[MAXN] ; int par[MAXN];
bool mark[MAXN];

void Dijkstra(int v)
{
    for(int i = 0 ; i < MAXN ; i++)
    {
        dist[i] = INF;
    }
    dist[v] = 0;

    set<pair<ll , int>> st;
    for(auto &i : vet)
    {
        st.insert({dist[i] , i});
    }

    while(st.size() != 0)
    {
        v = st.begin() -> Y;
        st.erase(st.begin());
        mark[v] = 1;
        for(pii i : adj[v])
        {
            ll u = i.X , w = i.Y;
            if(!mark[u] && dist[v] + w < dist[u])
            {
                st.erase({dist[u] , u});
                par[u] = v;
                dist[u] = dist[v] + w;
                st.insert({dist[u] , u});
            }
        }
    }
}

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int v , u , w;
        cin >> v >> u >> w;
        adj[v].push_back({u , w});
        adj[u].push_back({v , w});
        vet.insert(v);
        vet.insert(u);
    }

    Dijkstra(1);
    if(!mark[n] || dist[n] == INF)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans = {n};
    while(n != 1)
    {
        n = par[n];
        ans.push_back(n);
    }
    for(int i = ans.size() - 1 ; i >= 0 ; i--)    cout << ans[i] << ends;

    return 0;
}