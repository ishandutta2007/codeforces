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
const int N = 200005, m = 30;

int n;
int a[N];

int z;
int t[N * m][2];

int ans;
void dfs(int x, int yans)
{
    if (!t[x][0] && !t[x][1])
    {
        ans = max(ans, yans + 1);
        return;
    }
    if (!t[x][0])
        dfs(t[x][1], yans);
    else if (!t[x][1])
        dfs(t[x][0], yans);
    else
    {
        dfs(t[x][0], yans + 1);
        dfs(t[x][1], yans + 1);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        int pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            int u = 0;
            if ((a[i] & (1 << j)))
                u = 1;

            if (!t[pos][u])
                t[pos][u] = ++z;

            pos = t[pos][u];
        }
    }

    dfs(0, 0);

    printf("%d\n", n - ans);
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