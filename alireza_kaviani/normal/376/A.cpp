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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

string s;
ll n , ind = 0 , ans = 0;

int main()
{
    fast_io;

    cin >> s;
    n = s.size();

    for(ll i = 0 ; i < n ; i++)
    {
        if(s[i] == '^') ind = i;
    }
    for(ll i = 0 ; i < n ; i++)
    {
        if(s[i] == '=') continue;
        ans += (ind - i) * (s[i] - 48);
    }
    if(ans == 0)    return cout << "balance" << endl , 0;
    if(ans > 0)     return cout << "left" << endl , 0;
    cout << "right" << endl;

    return 0;
}