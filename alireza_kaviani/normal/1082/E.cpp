#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
//#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> vec[MAXN] , sec[MAXN] , mx[MAXN];
ll n , c , t , ans , p[MAXN] , ind[MAXN] , cnt[MAXN];

int main() {
    fast_io;
    set_random;

    cin >> n >> c;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i];

    for(ll i = n ; i >= 1 ; i--)    cnt[i] = cnt[i + 1] + (p[i] == c);

    for(ll i = 1 ; i <= n ; i++)
    {
        ind[i] = vec[p[i]].size();
        if(ind[i] == 0) vec[p[i]].push_back(1);
        else            vec[p[i]].push_back(vec[p[i]].back() + 1);
        sec[p[i]].push_back(vec[p[i]].back() + cnt[i + 1]);
    }

    for(ll i = 0 ; i < MAXN ; i++)
    {
        for(ll j = SZ(sec[i]) - 1 ; j >= 0 ; j--)
        {
            if (mx[i].size() == 0)  mx[i].push_back(sec[i][j]);
            else                    mx[i].push_back(max(sec[i][j], mx[i].back()));
        }
        reverse(all(mx[i]));
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        ans = max(ans , t + mx[p[i]][ind[i]] - vec[p[i]][ind[i]] + 1);
        t += (p[i] == c);
    }
    cout << ans << endl;

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