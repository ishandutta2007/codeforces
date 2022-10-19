#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int n = 8;
int a[n][3];

long long dist(int i, int j)
{
    long long ans = 0;
    for (int k = 0; k < 3; ++k)
        ans += (a[i][k] - a[j][k]) * 1LL * (a[i][k] - a[j][k]);
    return ans;
}

bool stg()
{
    long long a = dist(0, 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            a = min(a, dist(i, j));
    }
    for (int i = 0; i < n; ++i)
    {
        int u[4] = {};
        for (int j = 0; j < n; ++j)
        {
            if (dist(i, j) == 0 * a)
                u[0]++;
            else if (dist(i, j) == 1 * a)
                u[1]++;
            else if (dist(i, j) == 2 * a)
                u[2]++;
            else if (dist(i, j) == 3 * a)
                u[3]++;
            else
                return false;
        }
        if (!(u[0] == 1 && u[1] == 3 && u[2] == 3 && u[3] == 1))
            return false;
    }
    return true;
}

void rec(int i)
{
    if (i == n)
    {
        if (stg())
        {
            printf("YES\n");
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < 3; ++j)
                    printf("%d ", a[i][j]);
                printf("\n");
            }
            exit(0);
        }
        return;
    }
    sort(a[i], a[i] + 3);
    do
    {
        rec(i + 1);
    } while (next_permutation(a[i], a[i] + 3));
}

int main()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
            scanf("%d", &a[i][j]);
    }
    rec(0);
    printf("NO\n");
    return 0;
}