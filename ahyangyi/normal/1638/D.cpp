#include <iostream>
#include <vector>

using namespace std;
const int N = 1024;
int cell[N][N];
int visited[N][N];
pair<int,int> order[N * N];
int color[N * N];

inline void clear(int i, int j)
{
    cell[i][j] = -1;
    cell[i + 1][j] = -1;
    cell[i][j + 1] = -1;
    cell[i + 1][j + 1] = -1;
}

inline int paintable(int i, int j)
{
    int color = cell[i][j];
    if (cell[i + 1][j] != -1)
    {
        if (color == -1)
        {
            color = cell[i + 1][j];
        }
        else
        {
            if (color != cell[i + 1][j])
            {
                return -2;
            }
        }
    }
    if (cell[i][j + 1] != -1)
    {
        if (color == -1)
        {
            color = cell[i][j + 1];
        }
        else
        {
            if (color != cell[i][j + 1])
            {
                return -2;
            }
        }
    }
    if (cell[i + 1][j + 1] != -1)
    {
        if (color == -1)
        {
            color = cell[i + 1][j + 1];
        }
        else
        {
            if (color != cell[i + 1][j + 1])
            {
                return -2;
            }
        }
    }
    return color;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> cell[i][j];
        }
    }
    
    int op = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            int p = paintable(i, j);
            if (p >= 0)
            {
                visited[i][j] = 1;
                color[op] = p;
                order[op++] = make_pair(i, j);
                clear(i, j);
            }
            else if (p == -1)
            {
                visited[i][j] = 1;
            }
        }
    }
    for (int p = 0; p < op; ++p)
    {
        int i = order[p].first;
        int j = order[p].second;

        for (int i2 = std::max(0, i - 1); i2 < i + 2 && i2 < n - 1; ++i2)
        {
            for (int j2 = std::max(0, j - 1); j2 < j + 2 && j2 < m - 1; ++j2)
            {
                if (!visited[i2][j2])
                {
                    int p = paintable(i2, j2);
                    if (p >= 0)
                    {
                        visited[i2][j2] = 1;
                        color[op] = p;
                        order[op++] = make_pair(i2, j2);
                        clear(i2, j2);
                    }
                    else if (p == -1)
                    {
                        visited[i2][j2] = 1;
                    }
                }
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (cell[i][j] != -1)
            {
                ok = false;
            }
        }
    }

    if (ok)
    {
        printf("%d\n", op);
        for (int i = op - 1; i >= 0; --i)
        {
            printf("%d %d %d\n", order[i].first + 1, order[i].second + 1, color[i]);
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}