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

const int MAXN = 1e5 + 10;
vector<int> num[MAXN];

int main()
{
    fast_io;

    int n , m , r;
    cin >> n >> m >> r;

    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        num[x % r].push_back(x);
    }

    for(int i = 0 ; i < r ; i++)
    {
        if(num[i].size() >= m)
        {
            cout << "Yes" << endl;
            for(int j = 0 ; j < m ; j++)
            {
                cout << num[i][j] << ends;
            }
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}