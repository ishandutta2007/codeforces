#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int a[7][7];
int s[3];
int d[7];
int c[3];
int sans, aans;
map <string, int> M;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    M["Anka"] = 0;
    M["Chapay"] = 1;
    M["Cleo"] = 2;
    M["Troll"] = 3;
    M["Dracul"] = 4;
    M["Snowy"] = 5;
    M["Hexadecimal"] = 6;

    int m;

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        string s, c;
        cin >> s >> c >> c;
        a[M[s]][M[c]] = 1;
    }

    for (int i = 0; i < 3; i++)
        cin >> s[i];

    sans = (int)(2e+9) + 103;

    for (int i = 0; i < 2187; i++)
    {
        int x = i;

        for (int j = 0; j < 3; j++)
            c[j] = 0;

        for (int j = 0; j < 7; j++)
        {
            d[j] = x % 3;
            x /= 3;
        }

        for (int j = 0; j < 7; j++)
            c[d[j]]++;

        bool flag = true;
        for (int j = 0; j < 3; j++)
            flag &= c[j] > 0;

        if (!flag) continue;

        int minx, maxx;
        maxx = 0;
        minx = (int)2e+9 + 7;
        for (int j = 0; j < 3; j++)
        {
            minx = min(minx, s[j] / c[j]);
            maxx = max(maxx, s[j] / c[j]);
        }
        int sx = maxx - minx;
        int sa = 0;

        for (int x = 0; x < 7; x++)
            for (int y = 0; y < 7; y++)
                sa += d[x] == d[y] && a[x][y];

        if (sx < sans || sx == sans && sa > aans)
        {
            sans = sx;
            aans = sa;
        }
    }
    printf("%d %d\n", sans, aans);
    return 0;
}