#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 600;
vector<ll> adj[MAXN] , A , B;
vector<pll> edge;
ll n , sum , ans , deg[MAXN] , start[MAXN] , mark[MAXN];

void dfs(ll v , ll p = -1)
{
    mark[v] = 1;
    start[v] = (p == -1 ? 0 : start[p] + 1);
    ans = max(ans , start[v]);
    for(ll u : adj[v])
    {
        if(!mark[u])    dfs(u , v);
    }
}

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> deg[i];
        if(deg[i] == 1) A.push_back(i);
        else            B.push_back(i);

        sum += deg[i];
    }
    if(sum / 2 < n - 1) return cout << "NO" << endl , 0;

    if(A.size() != 0)
    {
        edge.push_back({A[0] , B[0]});
        adj[A[0]].push_back(B[0]);
        adj[B[0]].push_back(A[0]);
        deg[A[0]]--;
        deg[B[0]]--;
    }

    for(ll i = 0 ; i < B.size() - 1 ; i++)
    {
        edge.push_back({B[i] , B[i + 1]});
        adj[B[i]].push_back(B[i + 1]);
        adj[B[i + 1]].push_back(B[i]);
        deg[B[i]]--;
        deg[B[i + 1]]--;
    }

    if(A.size() > 1)
    {
        edge.push_back({A[1] , B.back()});
        adj[A[1]].push_back(B.back());
        adj[B.back()].push_back(A[1]);
        deg[A[1]]--;
        deg[B.back()]--;
    }

    for(ll i = 2 ; i < A.size() ; i++)
    {
        for(ll j = 0 ; j < B.size() ; j++)
        {
            ll v = A[i] , u = B[j];
            if(deg[u] != 0)
            {
                edge.push_back({v , u});
                adj[v].push_back(u);
                adj[u].push_back(v);
                deg[v]--;
                deg[u]--;
                break;
            }
        }
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        fill(mark , mark  + MAXN , 0);
        fill(start , start + MAXN , 0);
        dfs(i);
    }
    cout << "YES " << ans << endl << edge.size() << endl;
    for(pll i : edge)   cout << i.X << sep << i.Y << endl;

    return 0;
}