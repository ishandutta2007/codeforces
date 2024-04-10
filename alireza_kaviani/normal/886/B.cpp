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

const int MAXN = 2e5 + 10;
bool mark[MAXN];

int main()
{
    fast_io;

    int n , ans = 0;
    cin >> n;

    int a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        if(!mark[a[i]])
        {
            ans = a[i];
        }
        mark[a[i]] = 1;
    }
    cout << ans << endl;

    return 0;
}