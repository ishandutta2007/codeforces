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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1010;
ll n , m , can[MAXN][MAXN];
string s[MAXN];
vector<pll> vec;

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s[i];
    }

    for(ll i = 1 ; i < n - 1 ; i++)
    {
        for(ll j = 1 ; j < m - 1 ; j++)
        {
            ll ans = 1;
            for(ll x = -1 ; x <= 1 ; x++)
            {
                for(ll y = -1 ; y <= 1 ; y++)
                {
                    if((x != 0 || y != 0) && s[i + x][j + y] != '#')
                    {
                        ans = 0;
                    }
                }
            }
            if(ans)
            {
                vec.push_back({i , j});
            }
        }
    }

    for(ll k = 0 ; k < vec.size() ; k++)
    {
        ll i = vec[k].X , j = vec[k].Y;
        for(ll x = -1 ; x <= 1 ; x++)
        {
            for(ll y = -1 ; y <= 1 ; y++)
            {
                if(x != 0 || y != 0)
                {
                    can[i + x][j + y] = 1;
                }
            }
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '#' && can[i][j] == 0)    return cout << "NO" << endl , 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}