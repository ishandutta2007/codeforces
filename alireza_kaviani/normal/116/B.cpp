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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int n , m , ans = 0;
    cin >> n >> m;

    string s[n];
    for(int i = 0 ; i < n ; i++)    cin >> s[i];

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(s[i][j] == 'P')
            {
                if(i + 1 < n && s[i + 1][j] == 'W')
                {
                    s[i + 1][j] = '.';
                    ans++;
                    continue;
                }
                if(i - 1 >= 0 && s[i - 1][j] == 'W')
                {
                    s[i - 1][j] = '.';
                    ans++;
                    continue;
                }
                if(j + 1 < m && s[i][j + 1] == 'W')
                {
                    s[i][j + 1] = '.';
                    ans++;
                    continue;
                }
                if(j - 1 >= 0 && s[i][j - 1] == 'W')
                {
                    s[i][j - 1] = '.';
                    ans++;
                    continue;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}