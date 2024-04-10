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

int p[101][2];

int main()
{
    fast_io;

    int n , ans = 0;
    cin >> n;

    int a[n * 2];
    for(int i = 0 ; i < n * 2 ; i++)
    {
        cin >> a[i];
        if(p[a[i]][0] == 0)
        {
            p[a[i]][0] = i + 1;
        }
        else
        {
            p[a[i]][1] = i + 1;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(a[i * 2] != a[i * 2 + 1])
        {
            int t = p[a[i * 2]][1] - 1;
            for(int j = t ; j > i * 2 + 1 ; j--)
            {
                swap(a[j] , a[j - 1]);
                ans++;
            }
        }

        for(int j = 1 ; j <= n; j++)
        {
            p[i][0] = 0 ; p[i][1] = 0;
        }

        for(int i = 0 ; i < n * 2 ; i++)
        {
            if(p[a[i]][0] == 0)
            {
                p[a[i]][0] = i + 1;
            }
            else
            {
                p[a[i]][1] = i + 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}