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

ll l1 , r1 , t1 , l2 , r2 , t2 , l3 , r3 , d , sz , ans;

int main()
{
    fast_io;

    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;

    if(t2 > t1)
    {
        swap(t1 , t2);
        swap(l1 , l2);
        swap(r1 , r2);
    }

    d = __gcd(t1 , t1 - t2);
    sz = r2 - l2;
    l2 %= d;
    r2 = l2 + sz;
    l3 = l2 + d * ((abs(l2 - l1) + d - 1) / d);
    r3 = l3 + sz;
    ans = max(ans , min(r3 , r1) - max(l3 , l1) + 1);

    r3 = r2 + d * (abs(r2 - r1) / d);
    l3 = r3 - sz;
    ans = max(ans , min(r3 , r1) - max(l3 , l1) + 1);
    cout << ans << endl;

    return 0;
}