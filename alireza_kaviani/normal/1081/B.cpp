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
ll n , p[MAXN] , cnt[MAXN] , ind[MAXN];
vector<ll> ans;

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];

    for(ll i = 0 ; i < n ; i++)
    {
        if(cnt[p[i]] == 0)
        {
            cnt[p[i]] = n - p[i] - 1;
            ind[p[i]] = i + 1;
            ans.push_back(i + 1);
        }
        else
        {
            cnt[p[i]]--;
            ans.push_back(ind[p[i]]);
        }
    }

    for(ll i = 0 ; i < MAXN ; i++)
    {
        if(cnt[i] != 0) return cout << "Impossible" << endl , 0;
    }
    cout << "Possible" << endl;
    for(ll i = 0 ; i < n ; i++) cout << ans[i] << sep;

    return 0;
}