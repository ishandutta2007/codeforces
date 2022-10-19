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

const ll MAXN = 1000;
ll n , k , sum , cur = 1 , a[MAXN][MAXN];

int main()
{
    fast_io;

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < k - 1 ; j++) a[i][j] = cur++;
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = k - 1 ; j < n ; j++)
        {
            a[i][j] = cur++;
            if(j == k - 1)  sum += a[i][j];
        }
    }

    cout << sum << endl;
    for(ll i = 0 ; i < n ; i++ , cout << endl)
        for(ll j = 0 ; j < n ; j++ , cout << ends)  cout << a[i][j];

    return 0;
}