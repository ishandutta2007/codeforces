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
//#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 1e6 + 10,
         _MAXN = 2010,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;


ll n , m , cnt , p , ind , speed[10] , mark[MAXN] , dist[MAXN] , ans[10] , par[MAXN] , t[MAXN];
vector<ll> adj[MAXN] , vec[10];
map<char , ll> mp;
string s[_MAXN];

ll Find(ll v)
{
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}
void Union(ll v , ll u)
{
    ll pv = Find(v) , pu = Find(u) , tv = t[pv] , tu = t[pu];
    if(tv < tu) swap(pv , pu);
    if(pu != pv)    par[pu] = pv;
}

void bfs(ll col)
{
    ll v;
    queue<ll> q;
    for(ll i : vec[col])    q.push(i);
    vec[col] = {};

    while(!q.empty())
    {
        v = q.front();
        q.pop();
        if(dist[v] == ind * speed[col])
        {
            vec[col].push_back(v);
            continue;
        }

        for(ll u : adj[v])
        {
            if(!mark[u])
            {
                mark[u] = col;
                dist[u] = dist[v] + 1;
                q.push(u);
                cnt++;
            }
        }
    }
}

int main()
{
    fast_io;
    fill(par , par + MAXN , -1);

    mp['.'] = 0;
    mp['#'] = 0;
    for(ll i = 1 ; i <= 9 ; i++)    mp[char(i + 48)] = i;

    cin >> n >> m >> p;
    for(ll i = 1 ; i <= p ; i++)    cin >> speed[i];
    for(ll i = 0 ; i < n ; i++) cin >> s[i];

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            t[i * m + j] = mp[s[i][j]];
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] != '#')
            {
                if(i != 0 && s[i - 1][j] != '#')
                {
                    adj[i * m + j].push_back((i - 1) * m + j);
                    adj[(i - 1) * m + j].push_back(i * m + j);
                    Union(i * m + j , (i - 1) * m + j);
                }
                if(j != 0 && s[i][j - 1] != '#')
                {
                    adj[i * m + j].push_back(i * m + j - 1);
                    adj[i * m + j - 1].push_back(i * m + j);
                    Union(i * m + j , i * m + j - 1);
                }
            }
            if('1' <= s[i][j] && s[i][j] <= '9')
            {
                vec[s[i][j] - '0'].push_back(i * m + j);
                mark[i * m + j] = s[i][j] - '0';
            }
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(t[Find(i * m + j)] == 0 || s[i][j] != '.')   cnt++;
        }
    }

    while(cnt != n * m)
    {
        ind++;
        for(ll i = 1 ; i <= p ; i++)    bfs(i);
    }
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            ans[mark[i * m + j]] += (s[i][j] != '#');
        }
    }
    for(ll i = 1 ; i <= p ; i++) cout << ans[i] << sep;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea
    5- don't forget printf and scanf can help you in your code speed
*/