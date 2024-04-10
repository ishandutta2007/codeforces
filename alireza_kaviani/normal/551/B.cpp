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

ll n , k , t , mx = 8e18 , sz , A , B , cnts[500] , cnta[500] , cntb[500];
string s , a , b , ans;

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> s >> a >> b;
    n = s.size() , k = a.size() , t = b.size();

    for(ll i = 0 ; i < n ; i++) cnts[s[i] - 97]++;
    for(ll i = 0 ; i < k ; i++) cnta[a[i] - 97]++;
    for(ll i = 0 ; i < t ; i++) cntb[b[i] - 97]++;

    for(ll i = 0 ; i < 26 ; i++)
    {
        if(cnta[i] != 0)    mx = min(mx , cnts[i] / cnta[i]);
    }

    for(ll i = 0 ; i <= mx ; i++)
    {
        ll x = 8e18;
        for(ll j = 0 ; j < 26 ; j++)
        {
            if(cntb[j] != 0)    x = min(x , (cnts[j] - i * cnta[j]) / cntb[j]);
        }
        if(x + i > sz)
        {
            sz = i + x;
            A = i , B = x;
        }
    }
    for(ll i = 0 ; i < A ; i++) ans += a;
    for(ll i = 0 ; i < B ; i++) ans += b;
    for(ll i = 0 ; i < 26 ; i++)
    {
        ans += string(cnts[i] - (cnta[i] * A + cntb[i] * B), i + 97);
    }
    cout << ans << endl;

    return 0;
}