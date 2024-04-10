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

    int n , m , star = -1;
    string s , t;
    cin >> n >> m >> s >> t;

    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '*') star = i;
    }
    if(star == -1)  return cout << (s == t ? "YES" : "NO") << endl , 0;
    if(n - 1 > m)   return cout << "NO" << endl , 0;

    for(int i = 0 ; i < star ; i++)
    {
        if(s[i] != t[i])    return cout << "NO" << endl , 0;
    }
    star = n - star - 1;
    for(int i = 0 ; i < star ; i++)
    {
        if(s[n - i - 1] != t[m - i - 1])    return cout << "NO" << endl , 0;
    }
    cout << "YES" << endl;

    return 0;
}