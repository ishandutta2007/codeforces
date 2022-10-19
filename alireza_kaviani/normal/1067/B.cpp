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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> adj[MAXN];
ll n , k , v , u , mark[MAXN] , cnt[MAXN];

void solve(vector<ll> vec) {
    if(vec.size() == 0) return;
    if(k == 0 && vec.size() != 1)
    {
        cout << "No" << endl;
        exit(0);
    }
    set<ll> st;
    k--;

    for(ll i : vec) mark[i] = 1;
    for(ll v : vec)
    {
        for(ll u : adj[v])
        {
            if(!mark[u])
            {
                cnt[u]++;
                st.insert(u);
            }
        }
    }
    solve(vector<ll>(st.begin() , st.end()));
}

int main() {
    fast_io;
    set_random;

    cin >> n >> k;
    for(ll i = 1 ; i < n ; i++)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<ll> vec;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(adj[i].size() == 1)
        {
            vec.push_back(i);
        }
    }
    solve(vec);

    for(ll i = 1 ; i <= n ; i++)
    {
        if(cnt[i] < 3 && cnt[i] != 0)   return cout << "No" << endl , 0;
    }
    if(accumulate(cnt , cnt + MAXN , 0) != n - 1)   return cout << "No" << endl , 0;
    if (k != -1)    return cout << "No" << endl , 0;
    cout << "Yes" << endl;

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