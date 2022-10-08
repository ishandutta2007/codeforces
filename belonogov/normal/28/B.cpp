#include <iostream>
#include <cstdio>

using namespace std;
int a[200][200];
int b[200];
int use[200];
int n, color = 1;

void dfs(int v)
{
    use[v] = color;
    for (int i = 0; i < n; i++)
    {
        if (a[v][i] && (! use[i]))
            dfs(i);
    }
}

int main()
{
  int x, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;
    }
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (i + x < n)
        {
            a[i][i + x] = 1;
            a[i + x][i] = 1;
        }
        if (i - x >= 0)
        {
            a[i - x][i] = 1;
            a[i][i - x] = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (use[i] == 0)
        {
            dfs(i);
            for (j = 0; j < n; j++)
            {
                if (use[j] == color && use[b[j]] != color)
                {
                    cout << "NO";
                    return 0;
                }
            }

            color++;
        }
    }
    /*for (i = 0; i < n; i++)
    {
        if (! use[i])
        {
            cout << "NO";
            return 0;
        }
    }
   */ cout << "YES";
    return 0;
}