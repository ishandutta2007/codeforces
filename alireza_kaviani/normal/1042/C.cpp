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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 2e5 + 10;
ll mark[MAXN];

void SET(ll &x)
{
    while(mark[x])  x++;
    mark[x] = 1;
}

int main()
{
    fast_io;

    ll n , t = 0;
    cin >> n;

    vector<ll> z , r;
    vector<pll> ne;
    for(ll i = 0 ; i < n ; i++)
    {
        ll x;
        cin >> x;
        if(x < 0)   ne.push_back({x , i + 1});
        if(x == 0)  z.push_back(i + 1);
    }
    if(ne.size() % 2 == 1)
    {
        Sort(ne);
        r.push_back(ne[ne.size() - 1].Y);
    }
    for(int i = 0 ; i < z.size() ; i++) r.push_back(z[i]);

    Sort(r);
    for(int i = 1 ; i < r.size() ; i++)
    {
        cout << 1 << ends << r[i - 1] << ends << r[i] << endl;
        mark[r[i - 1]] = mark[r[i]] = 1;
        t++;
    }
    if(r.size() && t != n - 1)
    {
        cout << 2 << ends << r[r.size() - 1] << endl;
        mark[r[r.size() - 1]] = 1;
        t++;
    }

    ll x = 1 , y = 1;
    SET(x);
    SET(y);
    for(ll i = t ; i < n - 1 ; i++)
    {
        cout << 1 << ends << x << ends << y << endl;
        x = y;
        SET(y);
    }

    return 0;
}