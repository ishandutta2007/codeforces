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

    int n , k;
    cin >> n >> k;

    for(int i = 0 ;i < n - k ; i++)
    {
        cout << i + 1 << ends;
    }
    for(int i = 0 ; i < k ; i++)
    {
        cout << (i % 2 == 0 ? n - i / 2 : (n - k) + i / 2 + 1) << ends;
    }

    return 0;
}