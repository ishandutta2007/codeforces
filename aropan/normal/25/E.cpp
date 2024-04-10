#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXL = 111111;
const int MAXN = 3 * MAXL;

int d[MAXN][26];
int v[MAXN][26];
int g[MAXN];

int p[MAXN];
char c[MAXN];

int f[MAXN];
int b[MAXN][8];

int n, m;
queue <pair <int, int> > q;
queue <int> Q;

int add(int I, int B, int L)
{
    B |= f[I];
    if (b[I][B]) return 0;

//    printf("%d %d %d\n", I, B, L);

    if (B == 7)
    {
        printf("%d\n", L - 1);
        return 1;
    }

    b[I][B] = L;
    q.push(make_pair(I, B));
    return 0;
}

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    for (int I = 0; I < 3; I++)
    {
        char s[MAXL];
        scanf("%s", &s);

        int l = strlen(s);
        int x = 0;
        for (int i = 0; i < l; i++)
        {
            s[i] -= 'a';
            if (d[x][s[i]] == 0)
            {
                n++;
                d[x][s[i]] = n;
                p[n] = x;
                c[n] = s[i];
            }
            x = d[x][s[i]];
        }
        f[x] |= 1 << I;
    }
    Q.push(0);

    while (Q.size())
    {
        int i = Q.front();
        Q.pop();

        f[i] |= f[p[i]];

        if (p[i])
        {
            int x = g[p[i]];
            while (x && d[x][c[i]] == 0) x = g[x];
            if (d[x][c[i]]) x = d[x][c[i]];
    
            g[i] = x;
        }


        for (int j = 0; j < 26; j++)
        {
            if (d[i][j])
            {
                Q.push(d[i][j]);
                v[i][j] = d[i][j];
            }
            else
                v[i][j] = v[g[i]][j];
        }
        f[i] |= f[g[i]];
    }
    while (q.size()) q.pop();

    add(0, 0, 1);
    while (q.size())
    {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 26; i++)
            if (add(v[x][i], y, b[x][y] + 1)) return 0;
    }
    return 0;
}