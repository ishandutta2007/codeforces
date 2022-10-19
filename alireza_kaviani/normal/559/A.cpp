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

int sqr(int x)
{
    return x * x;
}

int main()
{
    fast_io;

    int a[6];
    for(int i = 0 ;i < 6 ; i++)     cin >> a[i];

    cout << sqr(a[0] + a[1] + a[2]) - sqr(a[0]) - sqr(a[2]) - sqr(a[4]);

    return 0;
}