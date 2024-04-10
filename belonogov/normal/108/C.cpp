#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct edge
{
    int x, m, y;
};

const int MAXN = 1e3 + 10;
int n, m;
edge in[MAXN];
edge out[MAXN];
edge res[MAXN];
bool operator < (edge a, edge b)
{
    return a.x < b.x;
}

int main()
{
    //freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int i, x, y, q, uk = 0, mind, k;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        in[i].x = -1;
        out[i].x = -1;
    }
    for(i = 0; i < m; i++)
    {
        cin >> x >> y >> q;
        x--;
        y--;
        in[x].x = y;
        in[x].m = q;
        out[y].x = x;
        out[y].m = q;
    }
    for (i = 0; i < n; i++)
    {
        if (out[i].x == -1 && in[i].x != -1)
        {
            k = in[i].x;
            mind = out[k].m;
            while (in[k].x != -1)
            {
                k = in[k].x;
                if (mind > out[k].m)
                    mind = out[k].m;
            }
            res[uk].x = i;
            res[uk].y = k;
            res[uk].m = mind;
            uk++;
        }
    }
    cout << uk << endl;
    sort(res, res + uk);
    for (i = 0; i < uk; i++)
    {
        cout << res[i].x + 1 << " " << res[i].y + 1 << " " << res[i].m << endl;
    }


    return 0;
}