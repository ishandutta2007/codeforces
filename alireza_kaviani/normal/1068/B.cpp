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

const ll MAXN = 1e5 + 10;
ll pr[MAXN];

int main()
{
    fast_io;

    ll n , ans = 1 , y;
    cin >> n;

    y = n;
    for(ll i = 2 ; i * i <= n ; i++)
    {
        if(!pr[i])
        {
            ll cnt = 0 , x = n;
            while(x % i == 0)
            {
                cnt++;
                x /= i;
                y /= i;
            }
            for(ll j = i ; j < MAXN ; j += i)   pr[j] = 1;
            ans *= (cnt + 1);
        }
    }
    if(y != 1)  ans *= 2;
    cout << ans << endl;

    return 0;
}