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

bool cmp(int x , int y)
{
    return x > y;
}

int main()
{
    fast_io;

    int n , k;
    cin >> n >> k;

    int a[n] , b[k] , pos = 0;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < k ; i++)
    {
        cin >> b[i];
    }

    sort(b , b + k , cmp);

    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == 0)
        {
            a[i] = b[pos];
            pos++;
        }
        if(i != 0)
        {
            if(a[i] <= a[i - 1])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}