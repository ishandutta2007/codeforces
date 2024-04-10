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
const int N = 200015;

int n;
int w[N];
vector<int> g[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int x = 1; x <= n; ++x)
        scanf("%d", &w[x]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    ll s = 0;
    for (int x = 1; x <= n; ++x)
        s += w[x];

    vector<int> v;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < sz(g[x]) - 1; ++i)
            v.push_back(w[x]);
    }
    sort(all(v));
    reverse(all(v));

    printf("%lld ", s);
    for (int i = 0; i < sz(v); ++i)
    {
        s += v[i];
        printf("%lld ", s);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}