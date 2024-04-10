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
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 100 , MAXX = 3000 , INF = 8e18;
ll n , k , m , mx , sum , ans , t[MAXN] , dp[MAXX] , dp2[MAXX];

int main()
{
    fast_io;
    fill(dp , dp + MAXX ,INF);

    cin >> n >> k >> m;
    for(ll i = 0 ; i < k ; i++) t[i] = input() , sum += t[i];
    sort(t , t + k);
    partial_sum(t , t + k , t);

    dp[0] = 0;
    for(ll i = 0 ; i < n ; i++)
    {
        fill(dp2 , dp2 + MAXX , INF);
        for(ll j = 0 ; j < k ; j++)
        {
            for(ll l = 0 ; l < MAXX ; l++)
            {
                if(l + j + 1 < MAXX)
                {
                    dp2[l + j + 1] = min(dp2[l + j + 1], dp[l] + t[j]);
                }
            }
        }
        for(ll l = 0 ; l < MAXX ; l++)
        {
            if(l + k + 1 < MAXX)
            {
                dp2[l + k + 1] = min(dp2[l + k + 1], dp[l] + sum);
            }
        }
        for(ll j = 1 ; j < MAXX ; j++)  dp[j] = dp2[j];
    }
    for(ll i = 0 ; i < MAXX ; i++)
    {
        if(dp[i] <= m)  ans = i;
    }
    cout << ans << endl;

    return 0;
}