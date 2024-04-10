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

int main()
{
    fast_io;

    ll n , m , xl = 0 , yl = 0 , ansx = 0 , ansy = 0;

    cin >> n >> m;
    string s[n];
    for(int i = 0 ; i < n ; i++)    cin >> s[i];

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(s[i][j] == 'B')
            {
                xl = i; yl = j; goto A;
            }
        }
    }

A:  for(int i = 0 ; i + xl < n && i + yl < m ; i += 2)
    {
        int t = 1;
        for(int j = xl ; j <= xl + i ; j++)
        {
            for(int k = yl ; k <= yl + i ; k++)
            {
                if(s[j][k] != 'B')  t = 0;
            }
        }
        if(!t)  break;
        ansx = xl + i / 2;
        ansy = yl + i / 2;
    }
    cout << 1 + ansx << ends << 1 + ansy << endl;

    return 0;
}