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

ll n , k;
vector<ll> ans;

int main()
{
    fast_io;
    cin >> n >> k;

    for(ll i = 2 ; i * i <= n ;)
    {
        if(n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
        else    i++;
    }
    if(n != 1)  ans.push_back(n);
    if(ans.size() < k)  return cout << -1 << endl , 0;

    for(ll i = k ; i < ans.size() ; i++)    ans[k - 1] *= ans[i];
    for(ll i = 0 ; i < k ; i++) cout << ans[i] << sep;

    return 0;
}