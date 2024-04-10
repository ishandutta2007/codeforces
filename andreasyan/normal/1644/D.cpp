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
const int N = 200005, M = 998244353;

int n, m, k, q;
int x[N], y[N];

void solv()
{
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= q; ++i)
        cin >> x[i] >> y[i];

    int ans = 1;
    set<int> sx, sy;
    for (int i = q; i >= 1; --i)
    {
        if (sz(sx) == n || sz(sy) == m)
            break;
        if (sx.find(x[i]) != sx.end() && sy.find(y[i]) != sy.end())
            continue;
        sx.insert(x[i]);
        sy.insert(y[i]);
        ans = (ans * 1LL * k) % M;
    }

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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}