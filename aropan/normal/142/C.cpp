#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;


const int MAXN = 10;


typedef pair < pair <int, int>, int > mpair;


const char figure[4][3][3] = 
{
    {
      {'#', '#', '#'},
      {'.', '#', '.'},
      {'.', '#', '.'}
    },
    {
      {'.', '#', '.'},
      {'.', '#', '.'},
      {'#', '#', '#'}
    },
    {
      {'.', '.', '#'},
      {'#', '#', '#'},
      {'.', '.', '#'}
    },
    {
      {'#', '.', '.'},
      {'#', '#', '#'},
      {'#', '.', '.'}
    }
};

    
int a[MAXN][MAXN];
int n, m;

map < mpair, int > M;


int rec(int x, int y, int mask)
{
    if (m < y) return rec(x + 1, 1, mask);
    if (n < x + 2) return 0;
    mpair p = make_pair(make_pair(x, y), mask);
    if (M.find(p) != M.end()) return M[p];

    int &res = M[p] = 0;
    res = rec(x, y + 1, mask >> 1);

    if (y + 2 <= m)
    {
        for (int k = 0; k < 4; k++)
        {
            bool flag = true;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (figure[k][i][j] == '#')
                        flag &= (mask & (1 << (i * m + j))) == 0;
            if (!flag) continue;

            int nmask = mask;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (figure[k][i][j] == '#')
                        nmask |= (1 << (i * m + j));
            res = max(res, rec(x, y + 1, nmask >> 1) + 1);
        }
    }
    return res;
}

int recovery(int x, int y, int mask, int res)
{
    if (res == 0) return 0;
    if (m < y) return recovery(x + 1, 1, mask, res);
    if (n < x + 2) return 0;


    if (res == rec(x, y + 1, mask >> 1))
    {
        recovery(x, y + 1, mask >> 1, res);
        return 0;
    }

    if (y + 2 <= m)
    {
        for (int k = 0; k < 4; k++)
        {
            bool flag = true;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (figure[k][i][j] == '#')
                        flag &= (mask & (1 << (i * m + j))) == 0;
            if (!flag) continue;

            int nmask = mask;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (figure[k][i][j] == '#')
                        nmask |= (1 << (i * m + j));

            if (res == rec(x, y + 1, nmask >> 1) + 1)
            {
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        if (figure[k][i][j] == '#')
                            a[x + i][y + j] = res;
                recovery(x, y + 1, nmask >> 1, res - 1);
                return 0;
            }
        }
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
/*
    for (int i = 1; i < 10; i++)
        for (int j = i; j < 10; j++)
        {
            M.clear();
            n = i;
            m = j;
            int x = rec(1, 1, 0);
            M.clear();
            n = j;
            m = i;
            int y = rec(1, 1, 0);
            if (x != y)
            {
                puts("O_o");
            }
        }
//*/

    scanf("%d %d\n", &n, &m);
    int ans = rec(1, 1, 0);
    printf("%d\n", ans);
    recovery(1, 1, 0, ans);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%c", a[i][j]? 'A' + a[i][j] - 1 : '.');
        printf("\n");
    }
    return 0;
}