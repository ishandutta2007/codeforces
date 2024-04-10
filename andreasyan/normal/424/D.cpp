#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 302;
const int INF = 1000000009;

int n, m, t;
int tp, tu, td;
int a[N][N];

int pr[N][N], pl[N][N];
int pd[N][N], pu[N][N];

void solv()
{
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d", &tp, &tu, &td);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            pr[i][j] = pr[i][j - 1];
            if (a[i][j] > a[i][j - 1])
                pr[i][j] += tu;
            else if (a[i][j] < a[i][j - 1])
                pr[i][j] += td;
            else
                pr[i][j] += tp;
        }
        for (int j = m - 1; j >= 1; --j)
        {
            pl[i][j] = pl[i][j + 1];
            if (a[i][j] > a[i][j + 1])
                pl[i][j] += tu;
            else if (a[i][j] < a[i][j + 1])
                pl[i][j] += td;
            else
                pl[i][j] += tp;
        }
    }
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 2; i <= n; ++i)
        {
            pd[i][j] = pd[i - 1][j];
            if (a[i][j] > a[i - 1][j])
                pd[i][j] += tu;
            else if (a[i][j] < a[i - 1][j])
                pd[i][j] += td;
            else
                pd[i][j] += tp;
        }
        for (int i = n - 1; i >= 1; --i)
        {
            pu[i][j] = pu[i + 1][j];
            if (a[i][j] > a[i + 1][j])
                pu[i][j] += tu;
            else if (a[i][j] < a[i + 1][j])
                pu[i][j] += td;
            else
                pu[i][j] += tp;
        }
    }
    int minu = INF;
    int xx1, xx2;
    for (int x1 = 1; x1 <= n; ++x1)
    {
        for (int x2 = x1 + 2; x2 <= n; ++x2)
        {
            set<int> s;
            for (int j = 1; j <= m; ++j)
            {
                int y2 = j;
                int y2ans =
                pr[x1][y2] - pl[x2][y2] +
                pd[x2][y2] - pd[x1][y2];
                if (!s.empty())
                {
                    set<int>::iterator it = s.upper_bound(t - y2ans);
                    if (it != s.end())
                    {
                        if (abs(t - (*it + y2ans)) < minu)
                        {
                            minu = abs(t - (*it + y2ans));
                            xx1 = x1;
                            xx2 = x2;
                        }
                    }
                    if (it != s.begin())
                    {
                        --it;
                        if (abs(t - (*it + y2ans)) < minu)
                        {
                            minu = abs(t - (*it + y2ans));
                            xx1 = x1;
                            xx2 = x2;
                        }
                    }
                }
                if (j - 1 >= 1)
                {
                    int y1_ = j - 1;
                    int y1ans =
                     - pr[x1][y1_] + pl[x2][y1_] +
                    pu[x1][y1_] - pu[x2][y1_];
                    s.insert(y1ans);
                }
            }
        }
    }
    for (int x1 = xx1; x1 <= xx1; ++xx1)
    {
        for (int y1_ = 1; y1_ <= m; ++y1_)
        {
            for (int x2 = xx2; x2 <= xx2; ++x2)
            {
                for (int y2 = y1_ + 2; y2 <= m; ++y2)
                {
                    int yans =
                    pr[x1][y2] - pr[x1][y1_] + pl[x2][y1_] - pl[x2][y2] +
                    pd[x2][y2] - pd[x1][y2] + pu[x1][y1_] - pu[x2][y1_];
                    if (minu == abs(yans - t))
                    {
                        printf("%d %d %d %d\n", x1, y1_, x2, y2);
                        return;
                    }
                }
            }
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