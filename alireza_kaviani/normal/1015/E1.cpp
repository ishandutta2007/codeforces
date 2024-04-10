#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

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

const int MAXN = 200;
bool o[MAXN][MAXN];
pair<pii , int> ans[MAXN * MAXN];

int main()
{
    fast_io;

    int n , m , t = 0;
    cin >> n >> m;

    string s[n];
    for(int i = 0 ; i < n ; i++)    cin >> s[i];

    for(int i = 1 ; i < n - 1 ; i++)
    {
        for(int j = 1 ; j < m - 1 ; j++)
        {
            if(s[i][j] == '*')
            {
                int sz = 0;
                for(int k = 1 ; k < MAXN ; k++)
                {
                    int flag = 0;
                    if(i - k >= 0 && j - k >= 0 && i + k < n && j + k < m)
                    {
                        if(s[i - k][j] == '*' && s[i + k][j] == '*')
                        {
                            if(s[i][j - k] == '*' && s[i][j + k] == '*')
                            {
                                o[i - k][j] = o[i + k][j] = o[i][j - k] = o[i][j + k] = 1;
                                sz++;
                                flag = 1;
                            }
                        }
                    }
                    if(flag == 0)
                    {
                        if(sz >= 1)
                        {
                            o[i][j] = 1;
                            ans[t++] = {{i + 1 , j + 1} , sz};
                        }
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '*' && o[i][j] == 0)  return cout << -1 << endl , 0;
        }
    }

    cout << t << endl;
    for(int i = 0 ; i < t ; i++)    cout << ans[i].X.X << ends << ans[i].X.Y << ends << ans[i].Y << endl;

    return 0;
}