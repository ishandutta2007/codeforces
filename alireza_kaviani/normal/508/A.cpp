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

const int MAXN = 1e4 + 10;
bool pxl[MAXN][MAXN];

bool check(int x , int y)
{
    if(pxl[x][y] && pxl[x + 1][y] && pxl[x][y + 1] && pxl[x + 1][y + 1])    return 1;
    if(pxl[x][y] && pxl[x - 1][y] && pxl[x][y + 1] && pxl[x - 1][y + 1])    return 1;
    if(pxl[x][y] && pxl[x + 1][y] && pxl[x][y - 1] && pxl[x + 1][y - 1])    return 1;
    if(pxl[x][y] && pxl[x - 1][y] && pxl[x][y - 1] && pxl[x - 1][y - 1])    return 1;
    return 0;
}

int main()
{
    fast_io;

    int n , m , k;
    cin >> n >> m >> k;

    for(int i = 1 ; i <= k ; i++)
    {
        int x , y;
        cin >> x >> y;
        pxl[x][y] = 1;
        if(check(x , y))
        {
            return cout << i << endl , 0;
        }
    }
    cout << 0 << endl;
    return 0;
}