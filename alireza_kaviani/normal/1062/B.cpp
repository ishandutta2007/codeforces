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

const ll MAXN = 1e6 + 10;
ll n , ans , mx , PW = 1 , mul = 1 , cnt[MAXN];

int main()
{
    fast_io;

    cin >> n;
    if(n == 1)  return cout << 1 << sep << 0 << endl , 0;

    for(ll i = 2 ; i <= n ; i++)
    {
        if(n % i == 0)
        {
            mul *= i;
            while(n % i == 0)
            {
                n /= i;
                cnt[i]++;
            }
            mx = max(mx , cnt[i]);
        }
    }
    while(PW < mx)
    {
        PW *= 2;
        ans++;
    }
    for(ll i = 0 ; i < MAXN ; i++)
    {
        if(cnt[i] != 0 && cnt[i] != PW)
        {
            ans++;
            break;
        }
    }
    cout << mul << sep << ans << endl;

    return 0;
}