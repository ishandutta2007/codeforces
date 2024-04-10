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

int n, m;
int p[N];

int u[N];
vector<int> v[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &p[i]);
        u[p[i]] = i;
    }
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x = u[x];
        y = u[y];
        if (x > y)
            swap(x, y);
        v[y].push_back(x);
    }
    int maxu = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            maxu = max(maxu, v[i][j]);
        ans += (i - maxu);
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}