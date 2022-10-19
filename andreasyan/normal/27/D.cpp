#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;

char ans[N];

int n, m;
pair<int, int> a[N];

bool hat(int i, int j)
{
    if (a[i].first < a[j].first && a[j].first < a[i].second && a[i].second < a[j].second)
        return true;
    if (a[j].first < a[i].first && a[i].first < a[j].second && a[j].second < a[i].second)
        return true;
    return false;
}

void dfs(int i)
{
    for (int j = 0; j < m; ++j)
    {
        if (ans[j])
            continue;
        if (hat(i, j))
        {
            if (ans[i] == 'o')
                ans[j] = 'i';
            else
                ans[j] = 'o';
            dfs(j);
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a[i].first, &a[i].second);
        if (a[i].second < a[i].first)
            swap(a[i].first, a[i].second);
    }
    for (int i = 0; i < m; ++i)
    {
        if (!ans[i])
        {
            ans[i] = 'o';
            dfs(i);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            if (hat(i, j) && ans[i] == ans[j])
            {
                printf("Impossible\n");
                return;
            }
        }
    }
    printf("%s\n", ans);
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