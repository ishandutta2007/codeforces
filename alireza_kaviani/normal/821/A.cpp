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

    int n;
    cin >> n;

    int a[n][n];
    for(int i = 0 ; i < n ; i++)    for(int j = 0 ; j < n ; j++)    cin >> a[i][j];

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(a[i][j] != 1)
            {
                bool ok = 0;
                for(int k = 0 ;k < n ; k++)
                {
                    for(int l = 0 ; l < n ; l++)
                    {
                        if(k != i && l != j && a[i][j] == a[i][l] + a[k][j])
                        {
                            ok = 1;
                        }
                    }
                }
                if(!ok)
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}