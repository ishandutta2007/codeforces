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

ll n , m , x , y , pos;
string s , t;

int main()
{
    fast_io;

    cin >> s >> t;
    n = s.size() , m = t.size();

    for(ll i = 0 ; i < n ; i++)
        if(s[i] == '|') pos = i;

    x = pos , y = n - pos - 1;
    for(ll i = 0 ; i < m ; i++)
    {
        if(x < y)   s = t[i] + s , x++;
        else    s = s + t[i] , y++;
    }
    cout << (x == y ? s : "Impossible") << endl;

    return 0;
}