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

const ll MAXN = 12;
const ll MAXM = (1 << MAXN);
const ll MAXK = 110;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , m , q , k , cnt[MAXM] , w[MAXN] , ans[MAXM][MAXK];
string s , val[MAXM];

string toString(ll x)
{
    string ans = "";
    for(ll i = n - 1 ; i >= 0 ; i--)
    {
        if((x & (1 << i)))  ans += "1";
        else                ans += "0";
    }
    return ans;
}

ll toLL(string x)
{
    ll ans = 0;
    for(ll i = 0 ; i < n ; i++)
    {
        if(x[i] == '1') ans += (1 << (n - i - 1));
    }
    return ans;
}

ll get_wu(string x , string y)
{
    ll ans = 0;
    for(ll i = 0 ; i < n ; i++)
    {
        if(x[i] == y[i])    ans += w[i];
    }
    return ans;
}

int main()
{
    fast_io;

    cin >> n >> m >> q;
    for(ll i = 0 ; i < n ; i++) cin >> w[i];
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> s;
        cnt[toLL(s)]++;
    }

    for(ll i = 0 ; i < (1 << n) ; i++)
    {
        val[i] = toString(i);
    }

    for(ll i = 0 ; i < (1 << n) ; i++)
    {
        string x = val[i];
        for(ll j = 0 ; j < (1 << n) ; j++)
        {
            string y = val[j];
            ll wu = get_wu(x , y);
            if(wu <= 100)   ans[i][wu] += cnt[j];
        }
    }

    for(ll i = 0 ; i < q ; i++)
    {
        cin >> s >> k;
        ll x = toLL(s) , res = 0;
        for(ll j = 0 ; j <= k ; j++)
        {
            res += ans[x][j];
        }
        cout << res << endl;
    }

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/