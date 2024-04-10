#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int p = 1e6 + 3;


//vector<int> a;
long long res = 1;

int main()
{
    int i, n, m, r1, j, r;
    bool check;

    char ch;
    cin >> n >> m;
    int a[n][m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cin >> ch;
            if (ch  == '.')
                a[i][j] = -1;
            else
                a[i][j] = ch - '0';
        }
    for (i = 0; i < n; i++)
    {
        check = true;
        r = -1;
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != -1)
            {
                check = false;
                if (a[i][j] == 1 || a[i][j] == 2)
                    r1 = (1 + j) % 2;
                if (a[i][j] == 3 || a[i][j] == 4)
                    r1 = j % 2;

                if (r != -1 && r != r1)
                    res = 0;
                if (r == -1)
                    r = r1;

            }
        }
        if (check)
            res = (res * 2) % p;

    }
    /////////////////////////
    for (j = 0; j < m; j++)
    {
        check = true;
        r = -1;
        for (i = 0; i < n; i++)
        {
            if (a[i][j] != -1)
            {
                check = false;
                if (a[i][j] == 3 || a[i][j] == 2)
                    r1 = (1 + i) % 2;
                if (a[i][j] == 1 || a[i][j] == 4)
                    r1 = i % 2;

                if (r != -1 && r != r1)
                    res = 0;
                if (r == -1)
                    r = r1;

            }
        }
        if (check)
            res = (res * 2) % p;

    }
    cout << res;
    return 0;
}