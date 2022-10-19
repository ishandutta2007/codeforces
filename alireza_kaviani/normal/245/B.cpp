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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

ll n , ind;
string s;

int main()
{
    fast_io;

    cin >> s;
    n = s.size();
    if(s[0] == 'f')
    {
        cout << "ftp://";
        ind = 3;
    }
    else
    {
        cout << "http://";
        ind = 4;
    }
    for(ll i = ind + 1 ; i < n ; i++)
    {
        if(s.substr(i , 2) == "ru")
        {
            return cout << s.substr(ind , i - ind) << ".ru" << (i + 2 == n ? ' ' : '/') << s.substr(i + 2) << endl , 0;
        }
    }

    return 0;
}