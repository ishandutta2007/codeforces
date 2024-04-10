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

const ll MAXN = 2e5 + 10;
ll n , m , ind[2] , mark[MAXN] , mark2[MAXN];
char c[2];
string s[MAXN] , x[2] , y[2];

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n;
    m = 2 * n - 2;
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> s[i];
        if(s[i].size() == 1)        x[ind[0]++] = s[i];
        if(s[i].size() == n - 1)    y[ind[1]++] = s[i];
    }

    for(ll i = 0 ; i < 4 ; i++)
    {
        fill(mark , mark + MAXN , 0);
        fill(mark2 , mark2 + MAXN , 0);
        string str = x[i % 2] + y[i / 2] , ans = "";
        for(ll i = 0 ; i < m ; i++)
        {
            if(str.substr(0 , s[i].size()) == s[i] && !mark[s[i].size()])
            {
                mark[s[i].size()] = 1;
                ans += "P";
            }
            else
            {
                if(str.substr(n - s[i].size()) == s[i] && !mark2[s[i].size()])
                {
                    mark2[s[i].size()] = 1;
                    ans += 'S';
                }
                else    break;
            }
        }
        if(ans.size() == m) return cout << ans << endl , 0;
    }
    return 0;
}