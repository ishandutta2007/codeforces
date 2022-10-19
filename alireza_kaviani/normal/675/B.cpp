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

    ll n , a , b , c , d , ans = 0;
    cin >> n >> a >> b >> c >> d;

    for(int i = 1 ; i <= n ; i++)
    {
        int x = i + a + b;
        if(x - (a + c) <= n && x - (b + d) <= n && x - (c + d) <= n)
        {
            if(x - (a + c) >= 1 && x - (b + d) >= 1 && x - (c + d) >= 1)   ans++;
        }
    }
    cout << ans * n << endl;

    return 0;
}