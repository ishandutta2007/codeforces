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

int n;
int a[N];

vector<int> v[N];

int ans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        v[i].clear();

    for (int i = 1; i <= n; ++i)
    {
        v[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
        ans[i] = N;

    for (int i = 1; i <= n; ++i)
    {
        if (v[i].empty())
            continue;
        int maxu = v[i][0] - 1;
        for (int j = 0; j < sz(v[i]) - 1; ++j)
            maxu = max(maxu, v[i][j + 1] - v[i][j] - 1);
        maxu = max(maxu, n - v[i].back());
        ans[maxu + 1] = min(ans[maxu + 1], i);
    }

    for (int i = 2; i <= n; ++i)
        ans[i] = min(ans[i], ans[i - 1]);

    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == N)
            printf("-1 ");
        else
            printf("%d ", ans[i]);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}