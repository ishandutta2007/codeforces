#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 102;

int n;
char u[N][N];
int a[N];
int q[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (u[i] + 1));
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> ans;
    while (1)
    {
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            if (q[i] == a[i])
            {
                z = true;
                ans.push_back(i);
                for (int j = 1; j <= n; ++j)
                {
                    if (u[i][j] == '1')
                        ++q[j];
                }
                break;
            }
        }
        if (!z)
        {
            printf("%d\n", ans.size());
            for (int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}