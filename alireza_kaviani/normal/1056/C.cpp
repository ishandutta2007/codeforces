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

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , m , x , y , l , t[MAXN] , h[MAXN] , mark[MAXN];
pll p[MAXN] , s[MAXN];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> m;
    for(ll i = 1 ; i <= 2 * n ; i++)
    {
        cin >> t[i];
        p[i] = {t[i] , i};
    }
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> x >> y;
        h[x] = y , h[y] = x , s[i] = {x , y};
    }

    sort(p + 1 , p + 1 + 2 * n , greater<pll>());
    cin >> x;
    for(ll i = 1 ; i <= 2 * n ; i++)
    {
        if(x % 2 == i % 2)
        {
            if(h[l] != 0 && !mark[h[l]])
            {
                cout << h[l] << endl;
                l = h[l];
                mark[l] = 1;
            }
            else
            {
                for(ll i = 0 ; i < m ; i++)
                {
                    if(!mark[s[i].X] && !mark[s[i].Y])
                    {
                        if(t[s[i].X] > t[s[i].Y])
                        {
                            cout << s[i].X << endl;
                            mark[s[i].X] = 1;
                            l = -1;
                            break;
                        }
                        else
                        {
                            cout << s[i].Y << endl;
                            mark[s[i].Y] = 1;
                            l = -1;
                            break;
                        }
                    }
                }
                if(l == -1) continue;
                for(ll i = 1 ; i <= 2 * n ; i++)
                {
                    if(!mark[p[i].Y])
                    {
                        cout << p[i].Y << endl;
                        mark[p[i].Y] = 1;
                        l = p[i].Y;
                        break;
                    }
                }
            }
        }
        else
        {
            cin >> l;
            mark[l] = 1;
        }
    }

    return 0;
}