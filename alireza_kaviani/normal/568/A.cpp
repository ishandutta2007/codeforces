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

const ll MAXN = 5e6 + 10;
ll p , q , c1 , c2 , ans , pr[MAXN];

ll pal(ll x)
{
    string s = "";
    while(x != 0)
    {
        s += string(1 , (x % 10) + 48);
        x /= 10;
    }
    for(ll i = 0 ; i < s.size() ; i++)
    {
        if(s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;
}

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> p >> q;
    pr[1] = 1;
    for(ll i = 2 ; i * i < MAXN ; i++)
    {
        if(!pr[i])
        {
            for(ll j = i * i ; j < MAXN ; j += i)   pr[j] = 1;
        }
    }

    for(ll i = 1 ; i < MAXN ; i++)
    {
        if(!pr[i])  c1++;
        if(pal(i))  c2++;
        if(p * c2 >= q * c1)    ans = max(ans , i);
    }
    cout << ans << endl;

    return 0;
}