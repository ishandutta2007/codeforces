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

    ll n , m , c;
    cin >> n >> m;

    set<string> st;
    for(int i = 0 ; i < n + m ; i++)
    {
        string s;
        cin >> s;
        st.insert(s);
    }

    c = (n + m) - ll(st.size());
    n -= c;
    m -= c;
    for(int i = 0 ; ; i++)
    {
        if(i % 2 == 0)
        {
            if(c > 0)   c--;
            else if(n > 0)  n--;
            else    return cout << "NO" << endl , 0;
        }
        else
        {
            if(c > 0)   c--;
            else if(m > 0)  m--;
            else    return cout << "YES" << endl , 0;
        }
    }

    return 0;
}