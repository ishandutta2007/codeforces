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

    int n , ans = 0;
    cin >> n;

    string s[n];
    for(int i = 0 ;i < n ; i++)cin >> s[i];

    for(int i = 0 ;i < n; i++)
    {
        int r = 0 , c = 0;
        for(int j = 0 ; j < n; j++)
        {
            if(s[j][i] == 'C')
            {
                r++;
            }
            if(s[i][j] == 'C')
            {
                c++;
            }
        }
        ans += (r * (r - 1) / 2) + (c * (c - 1) / 2) ;
    }
    cout << ans << endl;

    return 0;
}