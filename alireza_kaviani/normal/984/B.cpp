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
    cin >> n >> m;

    string s[n];
    int a[n + 2][m + 2];

    for(int i = 0; i < n + 2 ; i++)
    {
        for(int j = 0; j < m + 2 ; j++)
        {
            a[i][j] = -100;
        }
    }

    for(int i = 0; i < n ; i++)
    {
        cin >> s[i];
        for(int j = 0 ;j < m ; j++)
        {
            if(s[i][j] == '.')
            {
                a[i + 1][j + 1] = 0;
            }
            else if(s[i][j] == '*')
            {
                a[i + 1][j + 1] = -1;
            }
            else
            {
                a[i + 1][j + 1] = (int)s[i][j] - 48;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            int t = 0;
            for(int k = -1 ; k <= 1 ; k++)
            {
                for(int l = -1 ; l <= 1 ; l++)
                {
                    if(!(k == 0 && l == 0))
                    {
                        if(a[i + k][j + l] == -1)
                        {
                            t++;
                        }
                    }
                }
            }
            if(a[i][j] != -1 && a[i][j] != t)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}