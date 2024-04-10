#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;


const int MAXN = 100001;
const int MAXM = 200001;
const int INF = (int)1e+9;

int n, m, k;
int f[MAXN];
int last[MAXN];
int next[MAXM], dest[MAXM];
int a[MAXN];
int d[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        dest[i] = y;
        next[i] = last[x];
        last[x] = i;

        dest[i + m] = x;
        next[i + m] = last[y];
        last[y] = i + m;
    }


    for (int i = 1; i <= n; i++)
        if (!f[i])
        {
            a[k] = 0;
            queue <int> q;
            q.push(i);
            f[i] = true;

            while (q.size())
            {
                a[k]++;
                int x = q.front();
                q.pop();
                for (int j = last[x]; j; j = next[j])
                    if (!f[dest[j]])
                    {
                        f[dest[j]] = true;
                        q.push(dest[j]);
                    }
            }
            k++;
        }
    sort(a, a + k);


    int ans = INF;

    f[0] = true;
    for (int i = 1; i <= n; i++)
        f[i] = f[i / 10] && (i % 10 == 4 || i % 10 == 7);

    for (int i = 0; i <= n; i++)
        d[i] = INF;
    d[0] = 0;

    for (int i = 0, j = 0; i < k; i = j)
    {
        while (j < k && a[i] == a[j]) j++;

        queue <int> qf, qs;
        for (int k = n; k >= 0; k--)
            if (d[k] < INF && d[k] + 1 < ans)
                qf.push(k);

        for (int k = 0; k < j - i; k++)
        {
            while (qf.size())
            {
                int x = qf.front();
                qf.pop();
                if (x + a[i] <= n && d[x] + 1 < d[x + a[i]] && d[x] + 1 < ans)
                {
                    d[x + a[i]] = d[x] + 1;
                    if (f[x + a[i]]) ans = d[x] + 1;
                    qs.push(x + a[i]);
                }
            }
            swap(qf, qs);
        }
    }
    printf("%d\n", ans == INF? -1 : ans - 1);
    return 0;
}