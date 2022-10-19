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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> c[MAXN];
ll n , m , a , b , mn , mx , mx2 , ans;

ll dis(ll x , ll y , ll z)
{
    if(x == y)  return z;
    if(x <= y)  return y - x;
    y += n;
    return y - x;
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        c[a].push_back(b);
        mx = max(mx , ll(c[a].size()));
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        mx2 = 0;
        for(ll j = 1 ; j <= n ; j++)
        {
            mn = INF;
            for(ll k : c[j])
            {
                mn = min(mn , n * (ll(c[j].size()) - 1) + dis(i , j , 0) + dis(j , k , n));
            }
            if(mn != INF)   mx2 = max(mx2 , mn);
        }
        cout << ans + mx2 << sep;
    }

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/