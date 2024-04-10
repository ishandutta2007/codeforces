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

ll v(vector<ll> x , ll b)
{
    ll p = 1 , ans = 0;
    for(int i = x.size() - 1 ; i >= 0 ; i--)
    {
        ans += x[i] * p;
        p *= b;
    }
    return ans;
}

int main()
{
    fast_io;

    ll n , m , bx , by , vx , vy;
    cin >> n >> bx;

    vector<ll> x(n);
    for(int i = 0 ; i < n ; i++)    cin >> x[i];
    cin >> m >> by;
    vector<ll> y(m);
    for(int i = 0 ; i < m ; i++)    cin >> y[i];

    vx = v(x , bx) ; vy = v(y , by);
    if(vx > vy)
    {
        cout << '>' << endl ; return 0;
    }
    if(vx == vy)
    {
        cout << '=' << endl ; return 0;
    }
    cout << '<' << endl ;

    return 0;
}