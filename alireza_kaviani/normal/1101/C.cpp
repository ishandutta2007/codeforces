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
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 1e5 + 10;
ll q , n , l , r , can , cl , cr , t[MAXN];
pair<pll , ll> seg[MAXN];

ll common(pll x , pll y)
{
    return (x.Y >= y.X);
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> q;
    while(q--)
    {
        cin >> n; can = 0 ;
        for(ll i = 1 ; i <= n ; i++)
        {
            cin >> l >> r;
            seg[i] = {{l , r} , i};
            t[i] = 1;
        }
        sort(seg + 1 , seg + n + 1);

        cl = seg[1].X.X , cr = seg[1].X.Y;
        for(ll i = 1 ; i <= n ; i++)
        {
            if(common({cl , cr} , seg[i].X))
            {
                cr = max(cr , seg[i].X.Y);
                t[seg[i].Y] = 2;
            }
            if(t[seg[i].Y] == 1)    can = 1;
        }

        if(!can)
        {
            cout << -1 << endl;
            continue;
        }
        for(ll i = 1 ; i <= n ; i++)    cout << t[i] << sep;
        cout << endl;
    }

    return 0;
}