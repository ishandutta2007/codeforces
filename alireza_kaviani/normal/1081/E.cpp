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

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , t , sum , p[MAXN] , ans[MAXN];

ll sqr(ll x)
{
    return (ll(sqrt(x)) * ll(sqrt(x)) == x);
}

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n / 2 ; i++) cin >> p[i];

    for(ll i = 0 ; i < n / 2 ; i++)
    {
        ll mn = INF;
        for(ll j = 1 ; j * j <= p[i] ; j++)
        {
            if(p[i] % j == 0)
            {
                ll x = (j + p[i] / j) / 2;
                if(x < mn && x * x - p[i] > t * t && sqr(x * x - p[i])) mn = x;
            }
        }
        ans[i * 2] = mn * mn - t * t - p[i];
        ans[i * 2 + 1] = p[i];
        t = mn;
    }

    for(ll i = 0 ; i < n ; i++)
    {
        sum += ans[i];
        if(!sqr(sum))   return cout << "No" << endl , 0;
    }

    cout << "Yes" << endl;
    for(ll i = 0 ; i < n ; i++) cout << ans[i] << sep;

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