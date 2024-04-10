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

const ll MAXN = 1e5 + 10;
ll n , ok = 1 , diff = 0;
vector<pll> vec , a(MAXN);

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++) a[i] = {input() , i};
    sort(a.begin() , a.begin() + n);
    a[n] = {-1 , -1};

    for(ll i = 1 ; i <= n ; i++)
    {
        if(a[i].X != a[i - 1].X)
        {
            if(ok)  vec.push_back({a[i - 1].X , diff});
            ok = 1;
            diff = 0;
        }
        else
        {
            if(diff == 0)   diff = a[i].Y - a[i - 1].Y;
            else if(a[i].Y - a[i - 1].Y != diff)    ok = 0;
        }
    }

    cout << vec.size() << endl;
    for(pll i : vec)    cout << i.X << ends << i.Y << endl;

    return 0;
}