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

    int a[6] , sum;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];

    for(int i = 0 ; i < 6 ; i++)
    {
        for(int j = i + 1 ; j < 6 ; j++)
        {
            for(int k = j + 1 ; k < 6 ; k++)
            {
                if(a[i] + a[j] + a[k] == sum - a[i] - a[j] - a[k])
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}