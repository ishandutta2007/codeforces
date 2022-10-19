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

const int MAXN = 501;
int dpc[MAXN][MAXN] , dpr[MAXN][MAXN];

int main()
{
    fast_io;

    int h , w , q;
    cin >> h >> w;

    string s[h + 1];
    for(int i = 0 ; i <= w ; i++)   s[0] += '#';
    for(int i = 1 ; i <= h ; i++)   { cin >> s[i]; s[i] = "#" + s[i]; }

    for(int i = 1 ; i <= h ; i++)
    {
        for(int j = 1 ; j <= w ; j++)
        {
            dpc[i][j] = dpc[i - 1][j] + (s[i][j] == '.' && s[i - 1][j] == '.');
            dpr[i][j] = dpr[i][j - 1] + (s[i][j] == '.' && s[i][j - 1] == '.');
        }
    }

    cin >> q;
    while(q--)
    {
        int x1 , y1 , x2 , y2 , ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1 ; i <= y2 ; i++) ans += dpc[x2][i] - dpc[x1][i];
        for(int i = x1 ; i <= x2 ; i++) ans += dpr[i][y2] - dpr[i][y1];
        cout << ans << endl;
    }

    return 0;
}