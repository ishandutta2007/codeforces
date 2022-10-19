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

const ll MAXN = 1e5 + 10 , MOD = 1e9 + 7;
ll n , q , l , r , z , o , ans , cnt0[MAXN] , cnt1[MAXN];
string s;

ll pw(ll x, ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return pw(x, y / 2) * pw(x, y/2) % MOD;
    else
        return x * pw(x, y/2) * pw(x, y/2) % MOD;
}

int main()
{
    fast_io;

    cin >> n >> q >> s;

    for(ll i = 0 ; i < n ; i++)
    {
        if(s[i] == '0') cnt0[i + 1] = 1;
        else            cnt1[i + 1] = 1;
    }
    partial_sum(cnt0 , cnt0 + MAXN , cnt0);
    partial_sum(cnt1 , cnt1 + MAXN , cnt1);

    while(q--)
    {
        cin >> l >> r;
        z = cnt0[r] - cnt0[l - 1];
        o = cnt1[r] - cnt1[l - 1];
        ans = (pw(2 , o + z) - pw(2 , z) + MOD) % MOD;
        cout << ans % MOD << endl;
    }

    return 0;
}