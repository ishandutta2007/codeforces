#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int n = 9;

char a[n + 5][n + 5];

bool c[n + 5][n + 5];

void solv()
{
    for (int i = 0; i < n; ++i)
    {
        scanf(" %s", a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        int j = (i / 3) + (i % 3) * 3;
        if (a[i][j] == '1')
            a[i][j] = '2';
        else
            a[i][j] = '1';
    }
    for (int i = 0; i < n; ++i)
        printf("%s\n", a[i]);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}