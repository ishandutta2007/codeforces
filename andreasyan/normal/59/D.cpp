#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005;

int n;
int a[N];
int u[N];
int k;

int b[N][3];

bool so(int x, int y)
{
    return u[x] < u[y];
}

int dd[N];

bool so1(int x, int y)
{
    return u[b[x][0]] < u[b[y][0]];
}

bool c[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n * 3; ++i)
    {
        scanf("%d", &a[i]);
        u[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
            scanf("%d", &b[i][j]);
    }
    scanf("%d", &k);
    for (int i = 1; i <= n; ++i)
    {
        sort(b[i], b[i] + 3, so);
        dd[i] = i;
    }
    sort(dd + 1, dd + n + 1, so1);
    for (int ii = 1; ii <= n; ++ii)
    {
        int i = dd[ii];
        if (k == b[i][0])
        {
            queue<int> q;
            queue<int> qq;
            qq.push(min(b[i][1], b[i][2]));
            qq.push(max(b[i][1], b[i][2]));
            for (int j = 1; j <= n * 3; ++j)
            {
                if (j == b[i][0] || j == b[i][1] || j == b[i][2])
                    continue;
                if (c[j])
                    q.push(j);
                else
                    qq.push(j);
            }
            for (int i = 1; i < n * 3; ++i)
            {
                if (q.empty())
                {
                    printf("%d ", qq.front());
                    qq.pop();
                }
                else if (qq.empty())
                {
                    printf("%d ", q.front());
                    q.pop();
                }
                else
                {
                    if (q.front() < qq.front())
                    {
                        printf("%d ", q.front());
                        q.pop();
                    }
                    else
                    {
                        printf("%d ", qq.front());
                        qq.pop();
                    }
                }
            }
            printf("\n");
            return;
        }
        else if (k == b[i][1] || k == b[i][2])
        {
            for (int i = 1; i <= n * 3; ++i)
            {
                if (i == k)
                    continue;
                printf("%d ", i);
            }
            printf("\n");
            return;
        }
        else
        {
            for (int j = 0; j < 3; ++j)
                c[b[i][j]] = true;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}