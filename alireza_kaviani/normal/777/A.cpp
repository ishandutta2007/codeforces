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

    ll n , m , a[3] = {0 , 0 , 0};
    cin >> n >> m;

    n %= 6;
    a[m] = 1;
    for(int i = 0 ; i < n ; i++)
    {
        (i % 2 == n % 2 ? swap(a[2] , a[1]) : swap(a[1] , a[0]));
    }

    cout << (a[0] == 1 ? 0 : (a[1] == 1 ? 1 : 2)) << endl;

    return 0;
}