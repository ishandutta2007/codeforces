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

    int l[n] , r[n];
    for(int i = 0 ;i < n ; i++)
    {
        cin >> l[i] >> r[i];
    }

    cin >> m;
    int l2[m] , r2[m] , ans = 0;
    for(int i = 0 ;i < m ; i++)
    {
        cin >> l2[i] >> r2[i];
    }

    sort(l , l + n);
    sort(r , r + n);
    sort(l2 , l2 + m);
    sort(r2 , r2 + m);

    cout << max(max(0 ,  l[n - 1] - r2[0]) , max(0 , l2[m - 1] - r[0])) << endl;

    return 0;
}