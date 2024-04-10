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

const int MAXN = 1e5 + 10;
int see[MAXN] , see2[MAXN] , cnt[MAXN];

int main()
{
    fast_io;

    ll n , ans = 0;
    cin >> n;

    int a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    for(int i = 0 ; i < n ; i++)
    {
        if(!see[a[i]])
        {
            see[a[i]] = 1;
            cnt[i] = (i == 0 ? 1 : cnt[i - 1] + 1);
        }
        else
        {
            cnt[i] = cnt[i - 1];
        }
    }

    for(int i = n - 1 ; i >= 1 ; i--)
    {
        if(!see2[a[i]])
        {
            see2[a[i]] = 1;
            ans += cnt[i - 1];
        }
    }
    cout << ans << endl;

    return 0;
}