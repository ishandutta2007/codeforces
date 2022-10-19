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

    int n , ind = 1;
    cin >> n;

    int a[n] , b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++)
    {
        if(a[i] >= a[i - 1])
        {
            ind ++;
        }
        else
        {
            break;
        }
    }


    if(ind == n)
    {
        cout << 0 << endl;
        return 0;
    }

    rotate(a , a + ind , a + n);
    copy(a , a + n , b);
    sort(b , b + n);

    for(int i = 0 ;i < n; i++)
    {
        if(b[i] != a[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n - ind << endl;

    return 0;
}