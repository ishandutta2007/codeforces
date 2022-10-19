#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int m, k, n, s;
int a[N];

int qb;
int b[N];

int qq, q[N];
void ave(int x)
{
    q[x]++;
    if (q[x] == b[x])
        ++qq;
}
void han(int x)
{
    if (q[x] == b[x])
        --qq;
    q[x]--;
}

bool stg(int l, int r)
{
    if ((r - l + 1) > k)
    {
        return ((m - ((l - 1) % k) - ((r - l + 1) - k)) / k >= n);
    }
    return ((m - ((l - 1) % k)) / k >= n);
}

int main()
{
    scanf("%d%d%d%d", &m, &k, &n, &s);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= s; ++i)
    {
        int x;
        scanf("%d", &x);
        b[x]++;
    }

    for (int i = 1; i < N; ++i)
    {
        if (b[i])
            ++qb;
    }

    int l = 1, r = 0;
    while (1)
    {
        if (qb == qq)
        {
            if (stg(l, r))
                break;
            han(a[l]);
            ++l;
        }
        else
        {
            if (r == m)
            {
                printf("-1\n");
                return 0;
            }
            ++r;
            ave(a[r]);
        }
    }

    stg(l, r);

    vector<int> ans;
    for (int i = 1; i <= (l - 1) % k; ++i)
        ans.push_back(i);
    for (int i = l; i <= r; ++i)
    {
        if ((r - l + 1) - (ans.size() - ((l - 1) % k)) <= k)
            break;
        if (q[a[i]] > b[a[i]])
        {
            q[a[i]]--;
            ans.push_back(i);
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}