#include <bits/stdc++.h>
using namespace std;
const int N = 66;

int n, m;
char a[N][N];

bool stg0()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'P')
                return false;
        }
    }
    return true;
}

bool stg1()
{
    bool z = true;
    for (int j = 0; j < m; ++j)
    {
        if (a[0][j] == 'P')
        {
            z = false;
            break;
        }
    }
    if (z)
        return true;
    z = true;
    for (int j = 0; j < m; ++j)
    {
        if (a[n - 1][j] == 'P')
        {
            z = false;
            break;
        }
    }
    if (z)
        return true;
    z = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i][0] == 'P')
        {
            z = false;
            break;
        }
    }
    if (z)
        return true;
    z = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i][m - 1] == 'P')
        {
            z = false;
            break;
        }
    }
    if (z)
        return true;
    return false;
}

bool stg2()
{
    if (a[0][0] == 'A' || a[0][m - 1] == 'A' || a[n - 1][0] == 'A' || a[n - 1][m - 1] == 'A')
        return true;
    for (int i = 0; i < n; ++i)
    {
        bool z = true;
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'P')
            {
                z = false;
                break;
            }
        }
        if (z)
            return true;
    }
    for (int j = 0; j < m; ++j)
    {
        bool z = true;
        for (int i = 0; i < n; ++i)
        {
            if (a[i][j] == 'P')
            {
                z = false;
                break;
            }
        }
        if (z)
            return true;
    }
    return false;
}

bool stg3()
{
    for (int j = 0; j < m; ++j)
    {
        if (a[0][j] == 'A')
            return true;
    }
    for (int j = 0; j < m; ++j)
    {
        if (a[n - 1][j] == 'A')
            return true;
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i][0] == 'A')
            return true;
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i][m - 1] == 'A')
            return true;
    }
    return false;
}

bool stg4()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'A')
                return true;
        }
    }
    return false;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    if (stg0())
        printf("0\n");
    else if (stg1())
        printf("1\n");
    else if (stg2())
        printf("2\n");
    else if (stg3())
        printf("3\n");
    else if (stg4())
        printf("4\n");
    else
        printf("MORTAL\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}