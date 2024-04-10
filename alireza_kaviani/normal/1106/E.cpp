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
#define set_random                  mt19937_64 random(chrono::steady_clock::now().time_since_epoch().count());
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 1e5 + 10;
const ll MAXM = 210;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , m , k , l , r , d , w , mn = INF , dp[MAXN][MAXM];
vector<pair<pll , ll>> L[MAXN] , R[MAXN];
set<pair<pll , ll>> st;

void Fill()
{
    for(ll i = 1 ; i < MAXN ; i++)
    {
        fill(dp[i] , dp[i] + MAXM , INF);
    }
}

pll get(ll x)
{
    if(st.size() == 0)  return {0 , x};
    pll p = (*st.begin()).X;
    return {-p.X , -p.Y};
}

int main()
{
    fast_io;
    set_random;

    cin >> n >> m >> k;
    for(ll i = 0 ; i < k ; i++)
    {
        cin >> l >> r >> d >> w;
        L[l].push_back({{w , d} , i});
        R[r].push_back({{w , d} , i});
    }

    Fill();

    for(ll i = 1 ; i <= n ; i++)
    {
        for(pair<pll , ll> j : L[i])
        {
            st.insert({{-j.X.X , -j.X.Y} , j.Y});
        }
        pll p = get(i);

        for(ll j = 0 ; j <= m ; j++)
        {
            dp[p.Y][j] = min(dp[p.Y][j] , dp[i - 1][j] + p.X);
            if(j == 0)  continue;
            dp[i][j] = min(dp[i][j] , dp[i - 1][j - 1]);
        }

        for(pair<pll , ll> j : R[i])
        {
            st.erase({{-j.X.X , -j.X.Y} , j.Y});
        }
    }

    for(ll i = 0 ; i <= m ; i++)
    {
        mn = min(mn , dp[n][i]);
    }

    cout << mn << endl;

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