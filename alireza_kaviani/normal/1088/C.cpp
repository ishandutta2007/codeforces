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

const ll MAXN = 2010 , MOD = 2e5;
ll n , p[MAXN];
vector<pair<ll , pll>> vec;

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];
    for(ll i = n - 1 ; i >= 0 ; i--)
    {
        ll add = (MOD - (n - i) - (p[i] % MOD) + MOD) % MOD;
        vec.push_back({1 , {i + 1 , add}});
        for(ll j = 0 ; j <= i ; j++)    p[j] += add;
    }
    vec.push_back({2 , {n , MOD}});
    cout << vec.size() << endl;
    for(ll i = 0 ; i < vec.size() ; i++)    cout << vec[i].X << sep << vec[i].Y.X << sep << vec[i].Y.Y << endl;

    return 0;
}