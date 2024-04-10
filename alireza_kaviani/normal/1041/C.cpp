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

const ll MAXN = 1e6;
ll n , m , d , x , ans[MAXN] , ind = 0 , sz = 1;
pll a[MAXN];
priority_queue<pll , vector<pll> , greater<pll>> last;

int main()
{
    fast_io;

    cin >> n >> m >> d;
    for(ll i = 0 ; i < n ; i++) a[i] = {input() , i};
    sort(a , a + n);

    ans[a[0].Y] = 0;
    last.push({a[0].X , 0});

    for(ll i = 1 ; i < n ; i++)
    {
        if(a[i].X > last.top().X + d)
        {
            ans[a[i].Y] = last.top().Y;
            last.pop();
            last.push({a[i].X , ans[a[i].Y]});
        }
        else
        {
            ans[a[i].Y] = last.size();
            last.push({a[i].X , ans[a[i].Y]});
        }
    }
    cout << last.size() << endl;
    for(ll i = 0 ; i < n ; i++) cout << ans[i] + 1 << ends;

    return 0;
}