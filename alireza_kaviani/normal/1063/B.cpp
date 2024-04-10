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
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 4e6 + 10,
         _MAXN = 2010,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

vector<pll> adj[MAXN];
priority_queue<pll , vector<pll> , greater<pll>> pq;
ll n , m , r , c , x , y , ans , dist[MAXN] , mark[MAXN];
string s[_MAXN];

void dijkstra(ll v)
{
    pq.push({dist[v] = 0 , v});

    while(!pq.empty())
    {
        v = pq.top().Y;
        pq.pop();

        if(mark[v]) continue;
        mark[v] = 1;

        for(ll i = 0 ; i < adj[v].size() ; i++)
        {
            ll u = adj[v][i].X , w = adj[v][i].Y;
            if(dist[u] > dist[v] + w)
            {
                pq.push({dist[u] = dist[v] + w , u});
            }
        }
    }
}

int main()
{
    fast_io;
    fill(dist , dist + MAXN , INF);

    cin >> n >> m >> r >> c >> x >> y;
    for(ll i = 0 ; i < n ; i++) cin >> s[i];

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '.')
            {
                if(i != 0 && s[i - 1][j] == '.')
                {
                    adj[i * m + j].push_back({(i - 1) * m + j , 0});
                    adj[(i - 1) * m + j].push_back({i * m + j , 0});
                }
                if(j != 0 && s[i][j - 1] == '.')
                {
                    adj[i * m + j].push_back({i * m + j - 1 , 1});
                    adj[i * m + j - 1].push_back({i * m + j , 1});
                }
            }
        }
    }

    r-- , c--;
    dijkstra(r * m + c);
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            ll dx , dy;
            if(j <= c)  dx = (c - j) + (dist[i * m + j] + j - c) / 2 , dy = dist[i * m + j] - dx;
            if(j > c)   dy = (j - c) + (dist[i * m + j] + c - j) / 2 , dx = dist[i * m + j] - dy;
            if(dx <= x && dy <= y)    ans += mark[i * m + j];
        }
    }
    cout << ans << endl;

    return 0;
}
/*
todo :
    1- set consants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea
    5- don't forget printf and scanf can help you in your code speed
*/