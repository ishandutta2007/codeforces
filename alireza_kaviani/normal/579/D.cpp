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

ll n , k , x , ans , p[MAXN] , seg[4 * MAXN];

void build(ll ind = 0 , ll l = 0 , ll r = n - 1)
{
    if(l == r)
    {
        seg[ind] = p[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(ind * 2 + 1 , l , mid);
    build(ind * 2 + 2 , mid + 1 , r);
    seg[ind] = (seg[ind * 2 + 1] | seg[ind * 2 + 2]);
}

void modify(ll x , ll val , ll ind = 0 , ll l = 0 , ll r = n - 1)
{
    if(x < l || r < x)  return;
    if(l == r)
    {
        seg[ind] = val;
        return;
    }
    ll mid = (l + r) / 2;
    modify(x , val , ind * 2 + 1 , l , mid);
    modify(x , val , ind * 2 + 2 , mid + 1 , r);
    seg[ind] = (seg[ind * 2 + 1] | seg[ind * 2 + 2]);
}

int main()
{
    fast_io;

    cin >> n >> k >> x;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];

    build();
    for(ll i = 0 ; i < n ; i++)
    {
        ll t = p[i];
        for(ll j = 0 ; j < k ; j++) t *= x;
        modify(i , t);
        ans = max(ans , seg[0]);
        modify(i , p[i]);
    }
    cout << ans << endl;

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