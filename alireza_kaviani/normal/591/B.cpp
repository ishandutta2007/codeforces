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

const int MAXN = 1 << 8;
char par[MAXN];

int main()
{
    fast_io;

    for(int i = 0 ; i < MAXN ; i++)
    {
        par[i] = i;
    }

    int n , m;
    string s;
    cin >> n >> m >> s;

    for(int i = 0 ; i < m ; i++)
    {
        char a , b;
        cin >> a >> b;
        for(int j = 0 ; j < MAXN ; j++)
        {
            par[j] = (par[j] == a ? b : (par[j] == b ? a : par[j]));
        }
    }
    for(int i = 0 ; i < n ; i++)    cout << par[s[i]];

    return 0;
}