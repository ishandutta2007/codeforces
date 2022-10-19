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

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1010;
const ll INF = 8e18;
const ll MOD1 = 998244353;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 1e9 + 9;

vector<ll> adj[MAXN];
ll n , t , v , u , k1 , k2 , root , sub1[MAXN] , sub2[MAXN];

ll DFS(ll v, ll p = -1) {
    if(sub1[v]) return v;

    ll ans = -1;
    for(ll u : adj[v])
    {
        if(u != p)
        {
            ans = DFS(u , v);
            if(ans != -1)   break;
        }
    }
    return ans;
}

int Fill()
{
    fill(adj , adj + MAXN , vector<ll>());
    fill(sub1 , sub1 + MAXN , 0);
    fill(sub2 , sub2 + MAXN , 0);

    cin >> n;
    if(n == -1) exit(0);
    for(ll i = 1 ; i < n ; i++)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    cin >> k1;
    for(ll i = 0 ; i < k1 ; i++)    sub1[input()] = 1;
    cin >> k2;
    for(ll i = 0 ; i < k2 ; i++)    sub2[root = input()] = 1;

    cout << "B" << sep << root << endl;
    cin >> root;
    ll ans = DFS(root);
    if(ans == -1)   return cout << "C -1" << endl , 0;
    cout << "A" << sep << ans << endl;
    cin >> ans;
    if(sub2[ans])   return cout << "C" << sep << DFS(root) << endl , 0;
    cout << "C -1" << endl;
    return 0;
}

void MAIN() {
    Fill();
}

int main() {
    fast_io;
    set_random;

    cin >> t;
    while(t--)  MAIN();

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