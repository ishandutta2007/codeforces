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
//#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll INF = 2e9;
const ll MOD = 1e9 + 7; // 998244353;

ll n , k , p[MAXN] , q[MAXN];

ll check(ll x)
{
    ll sum = 0 , t = n - x;
    for(ll i = 0 ; i < n - x ; i++)
    {
        q[i] = max(0LL , p[i] - (t + x - 1) / x);
        t--;
    }

    for(ll i = 0 ; i < n ; i++) sum += (i < n - x ? q[i] : p[i]);
    return (sum >= k);
}

int main()
{
    fast_io;

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];
    sort(p , p + n);

    ll l = 0 , r = INF;
    while(r - l > 1)
    {
        ll mid = (r + l) / 2;
        if(check(mid))  r = mid;
        else            l = mid;
    }
    cout << (r == INF ? -1 : r) << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/