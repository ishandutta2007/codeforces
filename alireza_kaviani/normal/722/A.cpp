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

    int n , h , m;
    string s;
    cin >> n >> s;
    h = (s[0] - 48) * 10 + s[1] - 48; m = (s[3] - 48) * 10 + s[4] - 48;

    if((n == 12 && (h > 12 || h == 0)) || (n == 24 && h > 23))  cout << (h % 10 == 0 ? 1 : 0) << s[1] << ":";
    else cout << s[0] << s[1] << ":";
    if(m > 59)  cout << 0 << s[4] << endl;
    else cout << s[3] << s[4] << endl;

    return 0;
}