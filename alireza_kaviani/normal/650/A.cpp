#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<ll , ll>  tx , ty;
map<pll , ll> ta;

int main()
{
    fast_io;

    ll n , ans = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        ll x , y;
        cin >> x >> y;
        tx[x]++;
        ty[y]++;
        ta[{x , y}]++;
    }

    for(auto &i : tx)   ans += i.Y * (i.Y - 1) / 2LL;
    for(auto &i : ty)   ans += i.Y * (i.Y - 1) / 2LL;
    for(auto &i : ta)   ans -= i.Y * (i.Y - 1) / 2LL;

    cout << ans << endl;

    return 0;
}