#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define L first
#define I second

const int MAXN = 1111;

int a[MAXN];
int ans[MAXN];
int x[MAXN], y[MAXN];

vector < pair <int, int> > d;
vector < pair <int, int> > q;
int n, m;

int s(int i, int j)
{
    i = (i + n) % n;
    j = (j + n) % n;
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}                             

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    d.resize(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &d[i].L);
        d[i].I = i + 2;
    }
    sort(d.begin(), d.end());

    q.resize(n / 2);
    for (int st = 0; st < 3; st++)
    {
        for (int i = 0; i < n / 2; i++)
        {
            q[i] = make_pair(s(st, st - 1) + s(st, st + 1), st % n);
            st = (st + 2) % n;
        }

        sort(q.begin(), q.end());

        bool flag = true;
        int last = 0;

        memset(ans, 0, sizeof(ans));

        for (int i = 0; i < (int)q.size() && flag; i++)
        {
            while (last < m && d[last].L < q[i].L) last++;

            flag &= last < m && d[last].L == q[i].L;
            ans[q[i].I] = d[last].I;

            last++;
        }

        if (flag)
        {
            printf("YES\n");
            for (int i = 0; i < n; i++)
            {
                if (i) printf(" ");
                printf("%d", ans[i] - 1);
            }
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}                                                                                            ;