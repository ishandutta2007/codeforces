#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXK = 5;
const int MAXN = 19;

const int xi[3] = {0, 1, 1};
const int yi[3] = {1, 0, 1};

int x[MAXN], y[MAXN];
int f[1 << MAXN];
int n;

int rec(int m)
{
    int &res = f[m];
    if (res != -1) return res;

    int a[MAXK][MAXK];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
        if ((1 << i) & m)
            a[x[i]][y[i]] = i + 1;

    res = 0;
    for (int i = 0; i < MAXK; i++)
        for (int j = 0; j < MAXK; j++)
            if (a[i][j])
            {
                for (int d = 0; d < 3; d++)
                {
                    int s = 0;
                    int xx = i, yy = j;
                    while (xx < MAXK && yy < MAXK && a[xx][yy])
                    {
                        s |= (1 << (a[xx][yy] - 1));
                        if (!rec(m ^ s))
                            return res = 1;

                        xx += xi[d];
                        yy += yi[d];
                    }
                }
            }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    for (int i = 0; i < MAXK; i++)
        for (int j = 0; j < MAXK; j++)
        {
            if (abs(i - j) > 2) continue;
            x[n] = i;
            y[n] = j;
            n++;
        }

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        m |= (1 << i) * (c == 'O');
    }

    memset(f, 0xff, sizeof(f));
    printf("%s\n", rec(m)? "Karlsson" : "Lillebror");

    return 0;
}