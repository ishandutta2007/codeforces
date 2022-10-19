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

string f(string s , int sz)
{
    if(sz % 2 == 1) return s;
    sz /= 2;
    string a = f(s.substr(0 , sz) , sz) , b = f(s.substr(sz ,sz) , sz);
    if(a > b)   return b + a;
    return a + b;
}

int main()
{
    fast_io;

    string s , k;
    cin >> s >> k;
    cout << (f(s , (int)s.size()) == f(k , (int)k.size()) ? "YES" : "NO") << endl;

    return 0;
}