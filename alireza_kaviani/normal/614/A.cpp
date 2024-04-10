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

int main()
{
    fast_io;

    ll l , r , p , lg = 1 , x = 1 , can = 0;
    cin >> l >> r >> p;

    while(r / x >= p)
    {
        lg++;
        x *= p;
    }

    for(int i = 0 ; i < lg ; i++)
    {
        if(l <= pw(p , i) && pw(p , i) <= r)    { cout << pw(p , i) << ends; can = 1 ;}
    }
    if(can == 0)    cout << -1 << endl;

    return 0;
}