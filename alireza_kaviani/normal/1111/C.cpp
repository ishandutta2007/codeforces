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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , k , a , b , p[MAXN];

ll can(ll l , ll r)
{
    ll ind = lower_bound(p , p + k , l) - p;
    if(p[k - 1] < l)    return 1;
    if(p[ind] <= r) return 0;
    return 1;
}

ll cnt(ll l , ll r)
{
    if(l > p[k - 1])    return 0;
    ll ind = lower_bound(p , p + k , l) - p , ind2 = upper_bound(p , p + k , r) - p - 1;
    return max(0LL , ind2 - ind + 1);
}


ll ans(ll l , ll r)
{
    if(can(l , r))
    {
        return a;
    }
    if(l == r)
    {
        return b * cnt(l , l);
    }
    ll mid = (l + r) / 2;
    return min(b * (r - l + 1) * cnt(l , r) , ans(l , mid) + ans(mid + 1 , r));
}

int main()
{
    fast_io;

    cin >> n >> k >> a >> b;
    for(ll i = 0 ; i < k ; i++) cin >> p[i];
    sort(p , p + k);
    cout << ans(1 , pw(2 , n , INF)) << endl;

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