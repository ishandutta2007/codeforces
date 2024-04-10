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

const ll MAXN = 1e5 + 10;
vector<ll> sub[MAXN];
ll n , m , ans , s[MAXN] , r[MAXN] , sum[MAXN];

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s[i] >> r[i];
        sub[s[i]].push_back(r[i]);
    }
    for(ll i = 0 ; i < MAXN ; i++)
    {
        sort(all(sub[i]) , greater<ll>());
        partial_sum(all(sub[i]) , sub[i].begin());
        for(ll j = 0 ; j < sub[i].size() ; j++)
        {
            if(sub[i][j] > 0)   sum[j] += sub[i][j];
        }
    }

    for(ll i = 0 ; i < MAXN ; i++)  ans = max(ans , sum[i]);
    cout << ans << endl;

    return 0;
}