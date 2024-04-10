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

const ll MAXN = 20;
ll n , l , r , x , mx , mn , sum , cnt , ans , p[MAXN];

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n >> l >> r >> x;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];

    for(ll i = 0 ; i < (1LL << n) ; i++)
    {
        mx = 0 , mn = 8e18 , sum = 0;
        for(ll j = 0 ; j < n ; j++)
        {
            if(i & (1LL << j))
            {
                mx = max(mx , p[j]);
                mn = min(mn , p[j]);
                sum += p[j];
                cnt++;
            }
        }
        if(cnt >= 2 && l <= sum && sum <= r && mx - mn >= x)    ans++;
    }
    cout << ans << endl;

    return 0;
}