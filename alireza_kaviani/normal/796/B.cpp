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

const int MAXN = 1e6 + 10;
bool mark[MAXN];

int main()
{
    fast_io;

    int n , m , k , b = 1;
    cin >> n >> m >> k;

    for(int i = 0 ; i < m ; i++)    mark[input()] = 1;
    while(k--)
    {
        int u , v;
        cin >> u >> v;
        if(!mark[b])
        {
            if(b == u)  b = v;
            else if(b == v) b = u;
        }
    }
    cout << b << endl;

    return 0;
}