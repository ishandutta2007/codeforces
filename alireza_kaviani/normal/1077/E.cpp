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

ll n , x , c , ans , p[MAXN];
map<ll , ll> cnt;
vector<ll> vec;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        cnt[p[i]]++;
    }
    for(auto &i : cnt)
    {
        vec.push_back(i.Y);
    }
    sort(all(vec));

    for(ll i = vec.size() - 1 ; i >= 0 ; i--)
    {
        x = vec[i] , c = 0;
        for(ll j = i ; j >= 0 ; j--)
        {
            c++;
            ans = max(ans , x * (pw(2 , c , INF) - 1));
            if(x == 1 || j == 0)    break;
            x = min(x / 2 , vec[j - 1]);
        }
    }
    cout << ans << endl;

    return 0;
}