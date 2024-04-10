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

int n , a[6] , b[6] , ans = 0;

int main()
{
    fast_io;

    cin >> n;

    for(int i = 0 ;i < n ;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    for(int i = 0 ;i < n ; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }

    for(int i = 1 ; i <= 5 ; i++)
    {
        if(a[i] % 2 != b[i] % 2)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += abs(a[i] - (a[i] + b[i]) / 2);
    }
    cout << ans / 2 << endl;

    return 0;
}