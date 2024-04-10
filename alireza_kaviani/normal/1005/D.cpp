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
int INT(char n) {return n - 48 ;}

const int MAXN = 2e5 + 10;
int dp[MAXN] , sum[MAXN][3];

int main()
{
    fast_io;

    string s;
    cin >> s;

    int t = INT(s[0]);
    sum[0][t % 3] = 1;
    if(t % 3 == 0)
    {
        dp[0] = 1;
        sum[0][0] = 1;
    }

    for(int i = 1 ; i < s.size() ; i++)
    {
        int x = INT(s[i]);
        sum[i][x % 3] = 1;
        for(int j = 0 ; j < 3 ; j++)
        {
            if(sum[i - 1][j] == 1)  sum[i][(j + x) % 3] = 1;
        }
        if(sum[i][0])
        {
            dp[i] = dp[i - 1] + 1;
            sum[i][0] = 1;
            sum[i][1] = 0;
            sum[i][2] = 0;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[(int)s.size() - 1] << endl;

    return 0;
}