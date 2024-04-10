#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 102;

int n, m;
char a[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = 'B';
        }
        a[i][m] = 0;
    }
    a[0][0] = 'W';
    for (int i = 0; i < n; ++i)
        printf("%s\n", a[i]);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}