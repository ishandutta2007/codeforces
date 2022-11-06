#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

int n, m;
char buf[100010];
queue<int> q[301][301];
vector<int> v[301][301];
int c0[301][301];
int c1[301][310];

int lim;
vector<tuple<int, int, int, int>> ans;
void mv(int x1, int y1, int x2, int y2)
{
    assert((int)ans.size() < lim);
    assert(!q[x1][y1].empty());
    assert(x1 == x2 && y1 != y2 || y1 == y2 && x1 != x2);
    //assert(1 <= x1 && x1 <= n && 1 <= x2 && x2 <= n && 1 <= y1 && y1 <= m && 1 <= y2 && y2 <= m);

    q[x2][y2].push(q[x1][y1].front());
    q[x1][y1].pop();

    ans.push_back({ x1, y1, x2, y2 });
}

int cnt[301][301];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i, j, k;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            scanf("%s", buf);
            int len = strlen(buf);
            for(k = len - 1; k >= 0; k--)
            {
                q[i][j].push(buf[k] - '0');
                lim += 4;
            }
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            scanf("%s", buf);
            int len = strlen(buf);
            for(k = len - 1; k >= 0; k--)
                v[i][j].push_back(buf[k] - '0');
        }
    }

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cnt[i][j] = q[i][j].size();

    for(i = 0; i < cnt[1][1]; i++)
        mv(1, 1, n, 1);

    for(i = 0; i < cnt[n][m]; i++)
        mv(n, m, n, 1);

    cnt[n][1] = q[n][1].size();

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1 || i == n && j == m)
                continue;

            for(k = 0; k < cnt[i][j]; k++)
            {
                if(q[i][j].front() == 0)
                {
                    if(i == 1)
                        mv(i, j, i, 1);
                    else
                        mv(i, j, 1, j);
                }
                else
                {
                    if(i == n)
                        mv(i, j, i, m);
                    else
                        mv(i, j, n, j);
                }
            }
        }
    }

    for(i = 2; i <= m; i++)
        while(!q[1][i].empty())
            mv(1, i, 1, 1);

    for(i = 1; i < m; i++)
        while(!q[n][i].empty())
            mv(n, i, n, m);

    for(i = 2; i < n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            for(int x : v[i][j])
            {
                if(x == 0)
                {
                    if(j != 1)
                        mv(1, 1, 1, j);
                    mv(1, j, i, j);
                }
                else
                {
                    if(j != m)
                        mv(n, m, n, j);
                    mv(n, j, i, j);
                }
            }
        }
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            for(int x : v[i][j])
            {
                if(x == 0)
                    c0[i][j]++;
                else
                    c1[i][j]++;

            }
        }
    }

    for(i = 0; i < c0[1][1]; i++)
        mv(1, 1, 1, m);

    for(i = 0; i < c1[n][m]; i++)
        mv(n, m, n, 1);

    for(i = 2; i <= m; i++)
        for(j = 0; j < c0[n][i]; j++)
            mv(1, 1, 1, i);

    for(i = 1; i < m; i++)
        for(j = 0; j < c1[1][i]; j++)
            mv(n, m, n, i);

    for(i = 2; i <= m; i++)
    {
        for(int x : v[1][i])
        {
            if(x == 0)
                mv(1, 1, 1, i);
            else
                mv(n, i, 1, i);
        }
    }

    for(i = 1; i < m; i++)
    {
        for(int x : v[n][i])
        {
            if(x == 1)
                mv(n, m, n, i);
            else
                mv(1, i, n, i);
        }
    }

    for(int x : v[1][1])
    {
        if(x == 0)
            mv(1, m, 1, 1);
        else
            mv(n, 1, 1, 1);
    }

    for(int x : v[n][m])
    {
        if(x == 1)
            mv(n, 1, n, m);
        else
            mv(1, m, n, m);
    }

    printf("%d\n", (int)ans.size());
    for(auto t : ans)
    {
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = t;
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }

    return 0;
}