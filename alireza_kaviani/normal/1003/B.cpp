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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int a[2] , x , n;
    cin >> a[0] >> a[1] >> x;    n = a[0] + a[1];

    if(a[0] >= a[1])
    {
        if(x / 2 != a[1])   x--;
        int now = 0;
        for(int i = 0 ; i < x ; i++)
        {
            cout << now;
            a[now]--;
            now = 1 - now;
        }
        for(int i = 0 ; i < a[now] ; i++)
        {
            cout << now;
        }
        now = 1 - now;
        for(int i = 0 ; i < a[now] ; i++)
        {
            cout << now;
        }
    }
    else
    {
        if(x / 2 != a[0])   x--;
        int now = 1;
        for(int i = 0 ; i < x ; i++)
        {
            cout << now;
            a[now]--;
            now = 1 - now;
        }
        for(int i = 0 ; i < a[now] ; i++)
        {
            cout << now;
        }
        now = 1 - now;
        for(int i = 0 ; i < a[now] ; i++)
        {
            cout << now;
        }
    }

    return 0;
}