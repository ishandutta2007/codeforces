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

int main()
{
    fast_io;

    int n , k;
    cin >> n >> k;

    int x[n] , t[n] , ps1[n] , ps2[n] , sum , ans;
    for(int i = 0 ; i < n ; i++)    cin >> x[i];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> t[i];
        ps1[i] = x[i];
        ps2[i] = x[i] * t[i];
    }
    partial_sum(ps1 , ps1 + n , ps1);
    partial_sum(ps2 , ps2 + n , ps2);
    ans = sum = ps2[n - 1];

    for(int i = 0 ; i <= n - k ; i++)
    {
        int t = sum - (i == 0 ? ps2[k - 1] : ps2[i + k - 1] - ps2[i - 1]);
        ans = max(ans , t + (i == 0 ? ps1[k - 1] : ps1[i + k - 1] - ps1[i - 1]));
    }
    cout << ans << endl;

    return 0;
}