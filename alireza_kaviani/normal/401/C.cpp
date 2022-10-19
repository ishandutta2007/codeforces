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

bool bad(int n , int m)
{
    return m > (n + 1) * 2 || n > m + 1 || n < 0 || m < 0;
}

int main()
{
    fast_io;

    int n , m , xn , xm;
    cin >> n >> m;
    xn = n;xm = m;

    if(bad(n , m))
    {
        cout << -1 << endl;
        return 0;
    }
    if(m == (n + 1) * 2)
    {
        cout << 11;
        xm --;
    }
    if(m == n * 2 + 1)
    {
        cout << 1;
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << 0;
        if(m - n > i)
        {
            cout << 11;
            xm -= 2;
        }
        else if(xm)
        {
            cout << 1;
            xm--;
        }
    }

    return 0;
}