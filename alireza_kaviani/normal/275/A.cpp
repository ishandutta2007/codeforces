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

int a[5][5];

int main()
{
    fast_io;

    for(int i = 1 ; i <= 3 ; i++)
    {
        for(int j = 1 ; j <= 3 ; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1 ; i <= 3 ; i++ , cout << endl)
    {
        for(int j = 1 ; j <= 3 ; j++)
        {
            cout << 1 - (a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]) % 2;
        }
    }

    return 0;
}