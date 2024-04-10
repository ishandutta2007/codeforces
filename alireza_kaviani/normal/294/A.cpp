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

    int n , m;
    cin >> n;

    int a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    cin >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int x , y;
        cin >> x >> y;x--;

        int l = min(a[x] , y - 1) , r = max(a[x] - y , 0);
        if(x != 0)      a[x - 1] += l;
        if(x != n - 1)  a[x + 1] += r;
        a[x] = 0;
    }

    for(int i : a)
    {
        cout << i << endl;
    }

    return 0;
}