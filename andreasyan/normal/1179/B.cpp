#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2000006;

int n, m;

vector<pair<int, int> > a[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[i + j].push_back(m_p(i, j));
        }
    }
    int i, j;
    for (i = 2, j = n + m; i < j; ++i, --j)
    {
        for (int k = 0; k < a[i].size(); ++k)
        {
            printf("%d %d\n", a[i][k].first, a[i][k].second);
            printf("%d %d\n", a[j][a[i].size() - k - 1].first, a[j][a[i].size() - k- 1].second);
        }
    }
    if (i == j)
    {
        int k, k1;
        for (k = 0, k1 = a[i].size() - 1; k < k1; ++k, --k1)
        {
            printf("%d %d\n", a[i][k].first, a[i][k].second);
            printf("%d %d\n", a[i][k1].first, a[i][k1].second);
        }
        if (k == k1)
            printf("%d %d\n", a[i][k].first, a[i][k].second);
    }
    return 0;
}