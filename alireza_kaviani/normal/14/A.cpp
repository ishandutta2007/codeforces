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

const ll MAXN = 100 , INF = 8e18;
ll n , m , mnx = INF , mny = INF , mxx , mxy;
string s[MAXN];

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '*')
            {
                mxx = max(mxx , i);
                mxy = max(mxy , j);
                mnx = min(mnx , i);
                mny = min(mny , j);
            }
        }
    }

    for(ll i = mnx ; i <= mxx ; i++ , cout << endl)
    {
        for(ll j = mny ; j <= mxy ; j++)    cout << s[i][j];
    }

    return 0;
}