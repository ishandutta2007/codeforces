#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m;
int a[N];
int ll[N], rr[N];

vector<int> v[N];

int b[N];
int ml[N], mr[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &ll[i], &rr[i]);
    for (int i = 1; i <= m; ++i)
        v[rr[i]].push_back(ll[i]);
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    int minu = b[1];
    for (int i = 1; i <= n; ++i)
    {
        minu = min(minu, b[i]);
        ml[i] = minu;
        for (int j = 0; j < v[i].size(); ++j)
        {
            for (int k = v[i][j]; k <= i; ++k)
            {
                --b[k];
                minu = min(minu, b[k]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    for (int i = 1; i <= m; ++i)
        v[ll[i]].push_back(rr[i]);
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    minu = a[n];
    for (int i = n; i >= 1; --i)
    {
        minu = min(minu, b[i]);
        mr[i] = minu;
        for (int j = 0; j < v[i].size(); ++j)
        {
            for (int k = i; k <= v[i][j]; ++k)
            {
                --b[k];
                minu = min(minu, b[k]);
            }
        }
    }
    int ans = a[1] - min(ml[1], mr[1]);
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, a[i] - min(ml[i], mr[i]));
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
    {
        if (ans == a[i] - min(ml[i], mr[i]))
        {
            vector<int> ansv;
            for (int j = 1; j <= m; ++j)
            {
                if (!(ll[j] <= i && i <= rr[j]))
                    ansv.push_back(j);
            }
            printf("%d\n", ansv.size());
            for (int i = 0; i < ansv.size(); ++i)
                printf("%d ", ansv[i]);
            printf("\n");
            return;
        }
    }
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