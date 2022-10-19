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
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 1e5 + 10;
ll n , q;
string s , x;
set<string> st[MAXN];
map<string , ll> cnt;
map<string  , string> ans;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s;
        for(ll j = 0 ; j < s.size() ; j++)
        {
            x = "";
            for(ll k = j ; k < s.size() ; k++)
            {
                x += string(1 , s[k]);
                st[i].insert(x);
                ans[x] = s;
            }
        }
        for(auto &j : st[i])
        {
            cnt[j]++;
        }
    }

    cin >> q;
    while(q--)
    {
        cin >> s;
        cout << cnt[s] << sep << (cnt[s] == 0 ? "-" : ans[s]) << endl;
    }

    return 0;
}