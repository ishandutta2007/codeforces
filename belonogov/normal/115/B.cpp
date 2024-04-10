#include <iostream>
#include <cstdio>

using namespace std;
struct line
{
    int l, r;
};
line b[300];
int a[300][300];


int main()
{
    int uk, i, j, n, m, count, last;
    cin >> n >> m;
    string s;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        for (j = 0; j < m; j++)
            if (s[j] == 'W')
                a[i][j] = 1;
    }
    for (i = 0; i < n; i++)
    {
        j = 0;
        while(a[i][j] != 1 && j < m)
            j++;
        b[i].l = j;
        j = m - 1;
        while(a[i][j] != 1 && j >= 0)
            j--;
        b[i].r = j;
    }
    uk = 0;
    count = 0;
    last = 0;
    for (i = 0; i < n; i++)
    {
        if (b[i].l < m)
            last = i;
    }
    for (i = last; i > 0; i--)
    {
        if (b[i - 1].l >= m)
        {
            if (i % 2 == 0)
            {
                b[i - 1].l = b[i].l;
                b[i - 1].r = b[i].l;
            }
            else
            {
                b[i - 1].l = b[i].r;
                b[i - 1].r = b[i].r;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (b[i].r >= 0)
            {
                count += b[i].r - uk;
                uk = b[i].r;
            }
            if (i < n - 1 && b[i + 1].r > uk)
            {
                count += b[i + 1].r - uk;
                uk = b[i + 1].r;
            }
        }
        else
        {
            if (b[i].l < m)
            {
                count += uk - b[i].l;
                uk = b[i].l;
            }
            if (i < n - 1 && b[i + 1].l < uk)
            {
                count += uk - b[i + 1].l;
                uk = b[i + 1].l;
            }
        }
    }
    cout << count + last;
    return 0;
}