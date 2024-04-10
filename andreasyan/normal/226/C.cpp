#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005;
const pair<int, int> M = m_p(781908917, 956603663);
const int P = 300007;
 
pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}
 
pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}
 
pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}
 
pair<int, int> ast[N];
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}
 
bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
 
ll m, l, r, k;
 
struct ban
{
    ll a[2][2];
    ban()
    {
        memset(a, 0, sizeof a);
    }
};
 
ban operator*(const ban& a, const ban& b)
{
    ban res;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                res.a[i][j] = (res.a[i][j] + a.a[i][k] * b.a[k][j]) % m;
            }
        }
    }
    return res;
}
 
ban astt(ban x, ll n)
{
    ban res;
    for (int i = 0; i < 2; ++i)
        res.a[i][i] = 1;
    while (n)
    {
        if (n % 2 == 1)
            res = res * x;
        x = x * x;
        n /= 2;
    }
    return res;
}
 
void solv()
{
    cin >> m >> l >> r >> k;
    if (m == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<ll> v;
    for (ll i = 1; i * i <= r; ++i)
    {
        v.push_back(i);
        v.push_back(r / i);
    }
    for (ll i = 1; i * i <= (l - 1); ++i)
    {
        v.push_back(i);
        v.push_back((l - 1) / i);
    }
    ll ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        ll x = v[i];
        if (r / x - (l - 1) / x >= k)
            ans = max(ans, x);
    }
    ban t;
    t.a[0][1] = t.a[1][0] = t.a[1][1] = 1;
    t = astt(t, ans - 1);
    cout << t.a[1][1] << endl;
}
 
int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    solv();
    return 0;
}
 
//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}