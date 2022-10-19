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

const int MAXN = 1010;
int x[MAXN] , y[MAXN];

int main()
{
    fast_io;

    int n , m , all = 0;
    cin >> n >> m;

    string s[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        for(int j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '*')
            {
                x[i]++;
                y[j]++;
                all++;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(x[i] + y[j] - int(s[i][j] == '*') == all)
            {
                return cout << "YES" << endl << i + 1 << ends << j + 1 << endl , 0 ;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}