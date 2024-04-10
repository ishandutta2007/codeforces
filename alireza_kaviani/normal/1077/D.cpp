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
ll n , k , ind , ans[MAXN] , p[MAXN] , cnt[MAXN];
pll c[MAXN];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        cnt[p[i]]++;
    }
    for(ll i = 0 ; i < MAXN ; i++)  c[i] = {cnt[i] , i};
    sort(c , c + MAXN , greater<pll>());

    for(ll i = 1 ; i * k <= n ; i++)
    {
        ind = 0;
        for(ll j = 0 ; j < k ; j++)
        {
            for(ll l = 1 ; l * i <= c[j].X && ind < k ; l++ , ind++)
            {
                p[ind] = c[j].Y;
            }
        }
        if(ind != k)    break;
        for(ll j = 0 ; j < k ; j++) ans[j] = p[j];
    }

    for(ll i = 0 ; i < k ; i++) cout << ans[i] << sep;

    return 0;
}