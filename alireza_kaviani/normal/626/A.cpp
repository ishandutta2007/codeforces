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

ll n , ans;
string s;

int main()
{
    fast_io;

    cin >> n >> s;
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = i + 1 ; j < n ; j++)
        {
            ll x = 0 , y = 0;
            for(ll k = i ; k <= j ; k++)
            {
                if(s[k] == 'R') x++;
                if(s[k] == 'L') x--;
                if(s[k] == 'U') y++;
                if(s[k] == 'D') y--;
            }
            if(x == 0 && y == 0)    ans++;
        }
    }
    cout << ans << endl;

    return 0;
}