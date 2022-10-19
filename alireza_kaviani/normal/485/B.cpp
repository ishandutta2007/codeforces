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
    ll n;
    scanf("%I64d" , &n);
    cerr << 1;

    ll x[n] , y[n];
    for(int i = 0 ; i < n ; i++)    scanf("%I64d%I64d" , x + i , y + i);
    sort(x , x + n);
    sort(y , y + n);

    printf("%I64d" , max(x[n - 1] - x[0] , y[n - 1] - y[0]) * max(x[n - 1] - x[0] , y[n - 1] - y[0]));

    return 0;
}