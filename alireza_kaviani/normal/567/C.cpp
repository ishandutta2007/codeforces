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

const ll MAXN = 2e5 + 10;
map<ll , ll> cntl , cntr;
ll n , k , ans = 0 , a[MAXN];

int main()
{
    fast_io;

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        cntr[a[i]]++;
    }

    for(int i = 0 ; i < n ; i++)
    {
        cntr[a[i]]--;
        if(a[i] % k == 0)   ans += cntl[a[i] / k] * cntr[a[i] * k];
        cntl[a[i]]++;
    }
    cout << ans << endl;

    return 0;
}