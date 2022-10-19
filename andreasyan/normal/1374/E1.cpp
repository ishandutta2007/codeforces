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
const int N = 200005;
const ll INF = 1000000009000000009;

int n, k;
vector<int> v[2][2];

vector<ll> p[2][2];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        v[a][b].push_back(t);
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (v[i][j].empty())
                continue;
            sort(all(v[i][j]));
            p[i][j].assign(v[i][j].size(), 0);
            p[i][j][0] = v[i][j][0];
            for (int k = 1; k < v[i][j].size(); ++k)
                p[i][j][k] = p[i][j][k - 1] + v[i][j][k];
        }
    }
    ll ans = INF;
    for (int q = 0; q <= min(sz(v[1][1]), k); ++q)
    {
        ll yans = 0;
        if (q > 0)
            yans += p[1][1][q - 1];
        if (sz(v[1][0]) < (k - q))
            continue;
        if ((k - q) > 0)
            yans += p[1][0][(k - q) - 1];
        if (sz(v[0][1]) < (k - q))
            continue;
        if ((k - q) > 0)
            yans += p[0][1][(k - q) - 1];
        ans = min(ans, yans);
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}