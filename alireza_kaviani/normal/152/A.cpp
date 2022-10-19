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

    int n , m , ans = 0;
    cin >> n >> m;

    string s[n];
    for(int i = 0 ; i < n ;i++)     cin >> s[i];

    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            int t = 1;
            for(int k = 0 ;k < n ; k++)
            {
                if(i != k && s[i][j] - 48 < s[k][j] - 48)
                {
                    t = 0;
                }
            }
            if(t)
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}