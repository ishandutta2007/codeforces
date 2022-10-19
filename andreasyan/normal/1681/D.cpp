#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef unsigned long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int INF = 1000000009;

int n;
ll x;

map<ll, int> mp;
int rec(ll x)
{
    if (mp.find(x) != mp.end())
        return mp[x];

    mp[x] = INF;

    ll cx = x;
    vector<int> v;
    while (x)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    x = cx;

    assert(sz(v) <= n);
    if (sz(v) == n)
        return mp[x] = 0;

    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] == 0)
            continue;
        mp[x] = min(mp[x], rec(x * v[i]) + 1);
    }

    return mp[x];
}

void solv()
{
    cin >> n >> x;

    int ans = rec(x);
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}