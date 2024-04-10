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
const int N = 3003;

int n;
int a[N];

int q[N][N];
vector<pair<int, int> > v[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
    {
        v[i].clear();
        for (int j = 1; j <= n; ++j)
        {
            q[i][j] = 0;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            v[j - 1].push_back(m_p(a[j], a[i]));
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            q[a[j]][a[i]]++;
        }
        for (int j = 0; j < v[i].size(); ++j)
            ans += q[v[i][j].fi][v[i][j].se];
    }
    printf("%lld\n", ans);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}