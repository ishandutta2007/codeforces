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

ll n , t ,  cnt , ans;
string s;
vector<ll> vec;

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n >> s;
    s += "S";
    for(ll i = 0 ; i < n + 1 ; i++)
    {
        if(s[i] == 'S')
        {
            vec.push_back(t);
            t = 0;
        }
        else
        {
            t++;
            cnt++;
        }
    }

    for(ll i = 0 ; i < vec.size() ; i++)    ans = max(ans , vec[i]);
    for(ll i = 0 ; i < vec.size() - 1 ; i++)
    {
        ans = max(ans , vec[i] + vec[i + 1] + (vec[i] + vec[i + 1] != cnt));
    }
    cout << ans << endl;

    return 0;
}