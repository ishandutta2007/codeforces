#include <stdio.h>
#include <map>
#include <string>
#include <assert.h>

using namespace std;

int n, m;
int point[100];
int rank[100][100];
map<string, int> M;
string names[100];
int p, ans;
int candidate[100];

void getansByPoint ()
{
    if (ans != -1) return;
    int bp = -1, bc, bn;
    for (int i = 0; i < p; i ++)
        if (candidate[i])
        {
            if (point[i] > bp)
            {
                bp = point[i];
                bc = 1;
                bn = i;
            }
            else if (point[i] == bp)
            {
                bc ++;
            }
        }
    if (bc == 1)
        ans = bn;
    else
        for (int i = 0; i < p; i ++)
            if (candidate[i] && point[i] != bp)
                candidate[i] = 0;
}

void getansByRank (int x)
{
    if (ans != -1) return;
    int bp = -1, bc, bn;
    for (int i = 0; i < p; i ++)
        if (candidate[i])
        {
            if (rank[i][x] > bp)
            {
                bp = rank[i][x];
                bc = 1;
                bn = i;
            }
            else if (rank[i][x] == bp)
            {
                bc ++;
            }
        }
    if (bc == 1)
        ans = bn;
    else
        for (int i = 0; i < p; i ++)
            if (candidate[i] && rank[i][x] != bp)
                candidate[i] = 0;
}

int getName ()
{
    char buf[256];

    scanf("%s", buf);
    if (M.find(buf) == M.end())
    {
        names[p] = string(buf);
        M[buf] = p ++;
    }
    return M[buf];
}

inline int pts (int x)
{
    return x == 0? 25 :
        x == 1? 18 :
        x == 2? 15 :
        x == 3? 12 :
        x == 4? 10 :
        x == 5? 8 :
        x == 6? 6 :
        x == 7? 4 :
        x == 8? 2 :
        x == 9? 1 :
        0;
}

int main ()
{
    p = 0;

    for (int i = 0; i < 100; i ++)
    {
        point[i] = 0;
        for (int j = 0; j < 100; j ++)
            rank[i][j] = 0;
    }

    scanf ("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf ("%d", &m);
        for (int j = 0; j < m; j ++)
        {
            int x = getName ();
            point[x] += pts(j);
            rank[x][j] ++;
        }
    }

    ans = -1;
    for (int i = 0; i < p; i ++)
        candidate[i] = 1;
    getansByPoint();
    for (int i = 0; i < p; i ++)
        getansByRank(i);
    assert(ans != -1);
    printf ("%s\n", names[ans].c_str());

    ans = -1;
    for (int i = 0; i < p; i ++)
        candidate[i] = 1;
    getansByRank(0);
    getansByPoint();
    for (int i = 1; i < p; i ++)
        getansByRank(i);
    assert(ans != -1);
    printf ("%s\n", names[ans].c_str());

    return 0;
}