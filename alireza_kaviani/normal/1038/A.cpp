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

const int MAXK = 100;
ll cnt[MAXK];

int main()
{
    fast_io;

    ll n , k , imin = 8e18;
    string s;
    cin >> n >> k >> s;

    for(int i = 0 ; i < n ; i++)    cnt[s[i] - 65]++;
    for(int i = 0 ; i < k ; i++)    imin = min(imin , cnt[i]);
    cout << imin * k << endl;

    return 0;
}