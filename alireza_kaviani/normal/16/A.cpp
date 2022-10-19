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

    int n , m;
    string t;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)
    {
        string s;
        cin >> s;
        for(int j = 0 ; j < m - 1 ; j++)
            if(s[j] != s[j + 1])    return cout << "NO" << endl , 0;
        t += s[0];
    }
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(t[i] == t[i + 1])    return cout << "NO" << endl , 0;
    }
    cout << "YES" << endl;

    return 0;
}