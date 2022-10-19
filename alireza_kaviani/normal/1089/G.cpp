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

ll q , k , d , cnt , p[7];

ll get(ll x)
{
    ll ans = 8e18;
    for(ll i = 0 ; i < 20 ; i++)
    {
        for(ll j = i ; j < 20 ; j++)
        {
            ll cnt = 0;
            for(ll k = i ; k <= j ; k++)    cnt += p[k % 7];
            if(cnt == x)    ans = min(ans , j - i + 1);
        }
    }
    return ans;
}

void solve()
{
    cin >> k; cnt = 0;
    for(ll i = 0 ; i < 7 ; i++)
    {
        cin >> p[i];
        cnt += p[i];
    }
    d = (k % cnt == 0 ? k / cnt - 1 : k / cnt);
    cout << d * 7 + get(k - cnt * d) << endl;
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> q;
    while(q--)
    {
        solve();
    }

    return 0;
}