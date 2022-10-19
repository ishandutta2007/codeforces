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

const ll MOD = 1e9 + 7;
ll pw(ll a , ll b)
{
    return (b == 0 ? 1 : (b & 1 ? a : 1) * pw(a * a % MOD , b / 2) % MOD);
}

int main()
{
    fast_io;

    ll n;
    cin >> n;
    cout << (pw(27 , n) - pw(7 , n) + MOD) % MOD;

    return 0;
}