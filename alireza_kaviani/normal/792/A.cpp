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

map<int , int> cnt;

int main()
{
    fast_io;

    int n , mn = 2e9 + 20;
    cin >> n;

    int a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    sort(a , a + n);
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cnt[a[i + 1] - a[i]]++;
        mn = min(mn , a[i + 1] - a[i]);
    }
    cout << mn << ends << cnt[mn] << endl;

    return 0;
}