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

int main()
{
    fast_io;

    int n , m , ma = 1e9 ,l = 0 , r = 1e9;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        l = max(l , x);
        ma = min(ma , x);
    }
    for(int i = 0 ; i < m ; i++)
    {
        int x;
        cin >> x;
        r = min(r , x);
    }

    for(int i = l ; i < r; i++)
    {
        if(ma * 2 <= i)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}