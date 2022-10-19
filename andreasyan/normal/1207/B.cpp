#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 55;

int n, m;
int a[N][N];

vector<pair<int, int> > v;
int b[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
            {
                v.push_back(m_p(i, j));
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (b[i][j] != a[i][j])
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i)
        printf("%d %d\n", v[i].first, v[i].second);
    return 0;
}