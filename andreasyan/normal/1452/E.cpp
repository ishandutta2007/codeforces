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
const int N = 2003;

int n, m, k;
int l[N], r[N];

int a[N * 2];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &l[i], &r[i]);

    int ans = 0;
    for (int l1 = 1; l1 <= n - k + 1; ++l1)
    {
        memset(a, 0, sizeof a);

        int r1 = l1 + k - 1;
        int s = 0;
        for (int i = 1; i <= m; ++i)
        {
            int u = max(0, min(r[i], r1) - max(l[i], l1) + 1);
            s += u;
            int maxu = min(k, r[i] - l[i] + 1);
            if (u == maxu)
                continue;
            int l2s = l[i] + u - 1 - k + 1 + 1;
            int l2f = r[i] - u + 1 - 1;

            a[N + l2s]++;
            a[N + l2s + (maxu - u)]--;
            a[N + l2f + 2 - (maxu - u)]--;
            a[N + l2f + 2]++;
        }

        int yans = s;
        int q = 0;
        for (int i = -n; i <= n - k + 1; ++i)
        {
            q += a[N + i];
            yans += q;
            if (i >= 1)
                ans = max(ans, yans);
        }
    }
    printf("%d\n", ans);
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