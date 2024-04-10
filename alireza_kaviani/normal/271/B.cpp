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
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAX = 2e5 , MAXN = 510;
ll n , m , ans = 8e18 , p[MAX] , d[MAXN][MAXN];
vector<ll> pr;

int main()
{
    fast_io;

    for(ll i = 2 ; i * i <= MAX ; i++)
    {
        if(!p[i])
            for(ll j = i * i ; j < MAX ; j += i)   p[j] = 1;
    }
    for(ll i = 2 ; i < MAX ; i++)
        if(!p[i])   pr.push_back(i);

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            ll x = input();
            d[i][j] = pr[lower_bound(all(pr) , x) - pr.begin()] - x;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        ll sum = 0;
        for(int j = 0 ; j < m ; j++)    sum += d[i][j];
        ans = min(ans , sum);
    }
    for(int i = 0 ; i < m ; i++)
    {
        ll sum = 0;
        for(int j = 0 ; j < n ; j++)    sum += d[j][i];
        ans = min(ans , sum);
    }
    cout << ans << endl;

    return 0;
}