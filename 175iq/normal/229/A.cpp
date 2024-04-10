#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
char grid[105][10201];
vector <int> one[105];
int best[10201];

int dist (int i, int j)
{
    return min (abs (i - j), m - abs (i - j));
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) best[i] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                one[i].push_back(j);
            }
        }
        if (one[i].empty())
        {
            printf("-1\n");
            return 0;
        }
        int left = one[i][one[i].size() - 1];
        int right = one[i][0];
        int curi = 0;
        for (int j = 0; j < m; j++)
        {
            best[j] += min (dist (j, left), dist (j, right));
            if (j == right)
            {
                left = right;
                if (curi == one[i].size() - 1)
                {
                    curi = -1;
                }
                right = one[i][++curi];
            }
        }
    }
    int very_best = 321049857;
    for (int i = 0; i < m; i++)
    {
        very_best = min(very_best, best[i]);
    }
    printf("%d\n", very_best);
}