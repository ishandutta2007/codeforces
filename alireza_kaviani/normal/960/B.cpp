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

int main()
{
    fast_io;

    ll n , k1 , k2;
    cin >> n >> k1 >> k2;

    ll a[n] , b[n];
    vector<ll> vec;
    for(int i = 0 ; i < n ; i++)    { cin >> a[i];}
    for(int i = 0 ; i < n ; i++)    { cin >> b[i] ; vec.push_back(abs(a[i] - b[i]));}

    Sort(vec);
    for(int i = 0 ; i < k1 + k2 ; i++)
    {
        vec[n - 1] = abs(vec[n - 1] - 1);
        Sort(vec);
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++)    ans += vec[i] * vec[i];
    cout << ans << endl;

    return 0;
}