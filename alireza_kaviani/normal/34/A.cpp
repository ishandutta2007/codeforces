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

int main()
{
    fast_io;

    int n , st = 0 , MIN = 1e9;
    cin >> n;

    int a[n + 1];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    a[n] = a[0];

    for(int i = 0 ; i < n ; i++)
    {
        if(abs(a[i] - a[i + 1]) < MIN)
        {
            MIN = abs(a[i] - a[i + 1]);
            st = i;
        }
    }
    cout << st + 1 << ends << (st + 1) % n + 1;

    return 0;
}