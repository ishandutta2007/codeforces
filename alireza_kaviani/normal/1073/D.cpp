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
         MOD = 1e9 + 7;

ll n , t , ans , sm;
vector<ll> vec;

ll sum(vector<ll> vec)
{
    ll ans = 0;
    for(ll i = 0 ; i < vec.size() ; i++)    ans += vec[i];
    return ans;
}

void solve(vector<ll> vec)
{
    sm = sum(vec);
    if(vec.size() == 0)
    {
        return;
    }

    ans += t / sm * vec.size();
    t %= sm;
    sm = 0;

    vector<ll> sec;
    for(ll i = 0 ; i < vec.size() ; i++)
    {
        if(sm + vec[i] <= t)
        {
            sec.push_back(vec[i]);
            sm += vec[i];
        }
    }
    solve(sec);
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> t;
    for(ll i = 0 ; i < n ; i++) vec.push_back(input());

    solve(vec);
    cout << ans << endl;

    return 0;
}