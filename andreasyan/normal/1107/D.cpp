#include <bits/stdc++.h>
using namespace std;
const int N = 5210;

int n;
char a[N][N];
char b[N / 4];

char t[N][4];

int p[N][N];

int sum(int x1, int y1, int x2, int y2)
{
    x1++;
    y1++;
    x2++;
    y2++;
    return p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1];
}

int main()
{
    for (int x = 0; x < 16; ++x)
    {
        for (int i = 0; i < 4; ++i)
        {
            if ((x & (1 << i)))
                t[x][i] = '1';
            else
                t[x][i] = '0';
        }
        reverse(t[x], t[x] + 4);
    }

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf(" %s", &b);
        int kk = 0;
        for (int j = 0; j < n / 4; ++j)
        {
            if ('0' <= b[j] && b[j] <= '9')
            {
                for (int k = 0; k < 4; ++k)
                {
                    a[i][kk++] = t[b[j] - '0'][k];
                }
            }
            else
            {
                for (int k = 0; k < 4; ++k)
                {
                    a[i][kk++] = t[b[j] - 'A' + 10][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            if (a[i - 1][j - 1] == '1')
                ++p[i][j];
        }
    }

    for (int k = n; k >= 1; --k)
    {
        if (n % k == 0)
        {
            bool z = true;
            for (int i = 0; i < n; i += k)
            {
                bool zz = true;
                for (int j = 0; j < n; j += k)
                {
                    int s = sum(i, j, i + k - 1, j + k - 1);
                    if (!(s == 0 || s == k * k))
                    {
                        zz = false;
                        break;
                    }
                }
                if (!zz)
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                cout << k << endl;
                return 0;
            }
        }
    }
    return 0;
}