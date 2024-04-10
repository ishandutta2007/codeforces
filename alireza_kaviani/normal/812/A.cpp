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

int l[4] , s[4] , r[4] , p[4];

int main()
{
    fast_io;

    for(int i = 0 ; i < 4 ; i++)    cin >> l[i] >> s[i] >> r[i] >> p[i];

    for(int i = 0 ; i < 4 ; i++)
    {
        if(l[i] && p[(i + 3) % 4] || s[i] && p[(i + 2) % 4] || r[i] && p[(i + 1) % 4] || (l[i] || s[i] || r[i]) && p[i])    return cout << "YES" << endl , 0;
    }
    cout << "NO" << endl;

    return 0;
}