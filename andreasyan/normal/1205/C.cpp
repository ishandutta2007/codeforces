#include <bits/stdc++.h>
using namespace std;
const int N = 55;

int n;

bool qq[N][N][N][N];
bool qans[N][N][N][N];
bool qry(int x1, int y1, int x2, int y2)
{
    if (qq[x1][y1][x2][y2])
        return qans[x1][y1][x2][y2];
    qq[x1][y1][x2][y2] = true;
    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
    bool z;
    cin >> z;
    return qans[x1][y1][x2][y2] = z;
}

bool solvv(int x1, int y1, int x2, int y2, bool dp[N][N][N][N], bool mem[N][N][N][N], char a[N][N])
{
    if (x1 > x2)
        return true;
    if (y1 > y2)
        return true;
    if (mem[x1][y1][x2][y2])
        return dp[x1][y1][x2][y2];
    mem[x1][y1][x2][y2] = true;
    if (x1 + y1 + 2 > x2 + y2)
        return dp[x1][y1][x2][y2] = (a[x1][y1] == a[x2][y2]);
    if (a[x1][y1] != a[x2][y2])
        return dp[x1][y1][x2][y2] = false;
    if (x1 + 1 <= x2)
    {
        if (x2 - 1 >= x1 + 1)
        {
            if (solvv(x1 + 1, y1, x2 - 1, y2, dp, mem, a))
                return dp[x1][y1][x2][y2] = true;
        }
        if (y2 - 1 >= y1)
        {
            if (solvv(x1 + 1, y1, x2, y2 - 1, dp, mem, a))
                return dp[x1][y1][x2][y2] = true;
        }
    }
    if (y1 + 1 <= y2)
    {
        if (x2 - 1 >= x1)
        {
            if (solvv(x1, y1 + 1, x2 - 1, y2, dp, mem, a))
                return dp[x1][y1][x2][y2] = true;
        }
        if (y2 - 1 >= y1 + 1)
        {
            if (solvv(x1, y1 + 1, x2, y2 - 1, dp, mem, a))
                return dp[x1][y1][x2][y2] = true;
        }
    }
    return dp[x1][y1][x2][y2] = false;
}

void solv(char a[N][N], bool dp[N][N][N][N], bool mem[N][N][N][N])
{
    while (1)
    {
        bool z = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == '.')
                {
                    z = false;
                    break;
                }
            }
            if (!z)
                break;
        }
        if (z)
            break;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - 2; ++j)
            {
                if (a[i][j] != '.' && a[i][j + 2] == '.')
                {
                    if (qry(i, j, i, j + 2))
                    {
                        a[i][j + 2] = a[i][j];
                    }
                    else
                    {
                        a[i][j + 2] = (a[i][j] ^ 1);
                    }
                }
                if (a[i][j] == '.' && a[i][j + 2] != '.')
                {
                    if (qry(i, j, i, j + 2))
                    {
                        a[i][j] = a[i][j + 2];
                    }
                    else
                    {
                        a[i][j] = (a[i][j + 2] ^ 1);
                    }
                }
            }
        }
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < n - 2; ++i)
            {
                if (a[i][j] != '.' && a[i + 2][j] == '.')
                {
                    if (qry(i, j, i + 2, j))
                    {
                        a[i + 2][j] = a[i][j];
                    }
                    else
                    {
                        a[i + 2][j] = (a[i][j] ^ 1);
                    }
                }
                if (a[i][j] == '.' && a[i + 2][j] != '.')
                {
                    if (qry(i, j, i + 2, j))
                    {
                        a[i][j] = a[i + 2][j];
                    }
                    else
                    {
                        a[i][j] = (a[i + 2][j] ^ 1);
                    }
                }
            }
        }
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (a[i][j] != '.' && a[i + 1][j + 1] == '.')
                {
                    if (qry(i, j, i + 1, j + 1))
                    {
                        a[i + 1][j + 1] = a[i][j];
                    }
                    else
                    {
                        a[i + 1][j + 1] = (a[i][j] ^ 1);
                    }
                }
                if (a[i][j] == '.' && a[i + 1][j + 1] != '.')
                {
                    if (qry(i, j, i + 1, j + 1))
                    {
                        a[i][j] = a[i + 1][j + 1];
                    }
                    else
                    {
                        a[i][j] = (a[i + 1][j + 1] ^ 1);
                    }
                }
            }
        }
    }
    for (int x1 = 0; x1 < n; ++x1)
    {
        for (int x2 = x1; x2 < n; ++x2)
        {
            for (int y1 = 0; y1 < n; ++y1)
            {
                for (int y2 = y1; y2 < n; ++y2)
                {
                    solvv(x1, y1, x2, y2, dp, mem, a);
                }
            }
        }
    }
}

char a[N][N], b[N][N];
bool dpa[N][N][N][N], mema[N][N][N][N];
bool dpb[N][N][N][N], memb[N][N][N][N];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            a[i][j] = '.';
    }
    a[0][0] = '1';
    a[n - 1][n - 1] = '0';
    a[0][1] = '0';
    solv(a, dpa, mema);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            b[i][j] = '.';
    }
    b[0][0] = '1';
    b[n - 1][n - 1] = '0';
    b[0][1] = '1';
    solv(b, dpb, memb);
    for (int x1 = 0; x1 < n; ++x1)
    {
        for (int x2 = x1; x2 < n; ++x2)
        {
            for (int y1 = 0; y1 < n; ++y1)
            {
                for (int y2 = y1; y2 < n; ++y2)
                {
                    if (x1 + y1 + 2 <= x2 + y2 && dpa[x1][y1][x2][y2] != dpb[x1][y1][x2][y2])
                    {
                        if (qry(x1, y1, x2, y2) == dpa[x1][y1][x2][y2])
                        {
                            cout << '!' << endl;
                            for (int i = 0; i < n; ++i)
                                cout << a[i] << endl;
                            return 0;
                        }
                        else
                        {
                            cout << '!' << endl;
                            for(int i = 0; i < n; ++i)
                                cout << b[i] << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}