#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
#define YES cout << "YES" \
                 << "\n";
#define NO cout << "NO" \
                << "\n";
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

vector<ll> SieveOfEratosthenes(ll n)
{
    vector<ll> ans;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;

    for (int p = 2; p <= n; p++)
        if (prime[p])
            ans.push_back(p);
    return ans;
}
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve()
{
    ll i = 0, j = 0, n = 0, m = LLONG_MIN, s = 0;
    cin >> n;
    unordered_map<ll, ll> maps;
    fo(i, n)
    {
        cin >> j;
        if (maps.find(j) != maps.end())
            maps[j]++;
        else
            maps[j] = 1;
        if (m < j)
            m = j;
    }
    unordered_map<ll, ll> mapsc;
    mapsc = maps;

    vl ans;
    Fo(s, 2, m * 2 + 1)
    {
        ll c = 0;
        maps = mapsc;
        for (auto x : maps)
        {
            if (x.second > 0 && maps.find(s - x.first) != maps.end() && maps[s - x.first] > 0)
            {
                if (x.first != s - x.first)
                {
                    ll k = min(x.second, maps[s - x.first]);
                    maps[x.first] -= k;
                    maps[s - x.first] -= k;
                    c += k;
                }
                else
                {
                    ll k = x.second / 2;
                    maps[x.first] -= k;
                    maps[s - x.first] -= k;
                    c += k;
                }
            }
        }
        ans.pb(c);
    }
    ll maxi = LLONG_MIN;
    fo(i, ans.size())
    {
        if (ans[i] > maxi)
            maxi = ans[i];
    }
    cout << maxi << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    ll t = 1;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }

    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}