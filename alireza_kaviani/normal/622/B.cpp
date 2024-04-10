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
inline int INT(int x)   { return x - 48; }
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int h , m , t , a;
    string s;
    cin >> s >> a;
    h = INT(s[0]) * 10 + INT(s[1]) , m = INT(s[3]) * 10 + INT(s[4]) , t = (h * 60 + m + a) % (24 * 60);
    cout << t / 600 << t / 60 % 10 << ":" << t % 60 / 10 << t % 60 % 10;

    return 0;
}