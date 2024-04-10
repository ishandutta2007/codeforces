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

const ll MAXN = 1e6 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , ans , ps[MAXN] , seg[4 * MAXN];
string s;

void build(ll id , ll l , ll r)
{
    if(l == r)
    {
        seg[id] = ps[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2 + 1 , l , mid);
    build(id * 2 + 2 , mid + 1 , r);
    seg[id] = min(seg[id * 2 + 1] , seg[id * 2 + 2]);
}
ll get(ll id , ll l , ll r , ll ql , ll qr)
{
    if(r < ql || qr < l)    return INF;
    if(ql <= l && r <= qr)  return seg[id];

    ll mid = (l + r) / 2;
    return min(get(id * 2 + 1 , l , mid , ql , qr) , get(id * 2 + 2 , mid + 1 , r , ql , qr));
}

int main()
{
    fast_io;

    cin >> n >> s;
    for(ll i = 0 ; i < n ; i++) ps[i] = (s[i] == '(' ? 1 : -1);
    partial_sum(ps , ps + n , ps);
    build(0 , 0 , n - 1);

    for(ll i = 0 ; i < n ; i++)
    {
        ll x = get(0 , 0 , n - 1 , 0 , i - 1) , y = get(0 , 0 , n - 1 , i , n - 1);
        if(x >= 0 && y >= 2 * (s[i] == '(' ? 1 : -1))
        {
            if(ps[n - 1] - 2 * (s[i] == '(' ? 1 : -1) == 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea
    5- don't forget printf and scanf can help you in your code speed
*/