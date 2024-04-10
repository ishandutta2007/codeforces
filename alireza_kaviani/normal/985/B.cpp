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
    for(int i = 0 ; i < n; i++)
    {
        cin >> s[i];
    }

    for(int i = 0;i < n ; i++)
    {
        int f = 1;
        for(int j = 0 ;j < m ; j++)
        {
            if(s[i][j] == '1')
            {
                int t = 0;
                for(int k = 0 ;k < n; k++)
                {
                    if(s[k][j] == '1' && k != i)
                    {
                        t++;
                        break;
                    }
                }
                if(t == 0)
                {
                    f = 0;
                }
            }
        }
        if(f == 1)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}