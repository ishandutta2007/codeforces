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
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

string s , ans = "" , x = "";

int main()
{
    fast_io;

    cin >> s;
    for(ll i = 0 ; i < (1 << s.size()) ; i++)
    {
        ll t = 1;
        x = "";
        for(ll j = 0 ; j < s.size() ; j++)
        {
            if(i & (1 << j))    x += s[j];
        }
        for(ll j = 0 ; j < x.size() ; j++)
        {
            if(x[j] != x[x.size() - j - 1]) t = 0;
        }
        if(t)
        {
            ans = max(ans , x);
        }
    }
    cout << ans << endl;

    return 0;
}