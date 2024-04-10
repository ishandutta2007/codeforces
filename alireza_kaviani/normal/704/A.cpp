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
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 3e5 + 10;
ll n , q , t , x , num;
set<pll> all;
set<ll> app[MAXN];

int main()
{
    fast_io;

    cin >> n >> q;
    for(ll i = 0 ; i < q ; i++)
    {
        cin >> t >> x;
        if(t == 1)
        {
            all.insert({++num , x});
            app[x].insert(num);
        }
        if(t == 2)
        {
            for(auto &i : app[x])
            {
                all.erase({i , x});
            }
            app[x].clear();
        }
        if(t == 3)
        {
            for(auto &i : all)
            {
                if(i.X > x) break;
                app[i.Y].erase(i.X);
            }
            all.erase(all.begin() , all.upper_bound({x , 8e18}));
        }
        cout << all.size() << endl;
    }

    return 0;
}