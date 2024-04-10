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

map<ll , ll> cnt;

int main()
{
    fast_io;

    ll n , x , ans = 0;
    cin >> n >> x;

    ll a[n];
    for(int i = 0 ; i < n ; i++)    {cin >> a[i] ; cnt[a[i]]++;}
    for(int i = 0 ; i < n ; i++)    ans += cnt[x ^ a[i]] - (x == 0);
    cout << ans / 2 << endl;

    return 0;
}