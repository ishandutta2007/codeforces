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

    int n , o = 0 , t = 0;
    cin >> n;

    int a[n + 1];   a[0] = -1;
    for(int i = 1 ;i <= n ; i++)     cin >> a[i];

    for(int i = 1 ;i <= n ; i++)
    {
        (a[i] == 1 ? o++ : o = o);
        (a[i] == 1 && a[i - 1] == 1 ? t++ : t = t);
    }

    cout << max(0 , o * 2 - 1 - t) << endl;

    return 0;
}