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
#define endl                        '\n'
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

const ll MAXN = 3e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , k , t , c , sum , ans;
priority_queue<ll , vector<ll> , greater<ll>> pq;
pll p[MAXN];

int main() {
    fast_io;
    set_random;

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> t >> c;
        p[i] = {c , t};
    }
    sort(p , p + n , greater<pll>());

    for(ll i = 0 ; i < n ; i++)
    {
        ans = max(ans , (sum + p[i].Y) * p[i].X);
        if(k != 1 && (pq.size() < k - 1 || pq.top() < p[i].Y))
        {
            if(pq.size() == k - 1) {
                sum -= pq.top();
                pq.pop();
            }
            sum += p[i].Y;
            pq.push(p[i].Y);
        }
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