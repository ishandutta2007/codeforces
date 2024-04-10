#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
struct ban
{
    int x, y;
};

int n;
ban a[N];
int minx = N, miny = N;

bool c[202][202];
int q[202];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        minx = min(minx, a[i].x);
        miny = min(miny, a[i].y);
    }
    for (int i = 0; i < n; ++i)
    {
        a[i].x -= minx;
        a[i].y -= miny;
        c[a[i].x][a[i].y] = true;
        q[a[i].x]++;
    }

    if (n < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 1LL * n * (n - 1) * (n - 2) / 6 * 3;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int x1 = a[i].x;
            int y1 = a[i].y;
            int x2 = a[j].x;
            int y2 = a[j].y;
            if (x1 == x2)
            {
                ans -= (q[x1] - 2);
                continue;
            }
            for (int x = 0; x < 202; ++x)
            {
                if (x == x1 || x == x2)
                    continue;
                double y;
                if (y1 == y2)
                {
                    y = y1;
                }
                else
                {
                    y = ((x - x1) * (y2 - y1) + y1 * (x2 - x1) * 1.0) / (x2 - x1 + 0.0);
                }
                int yy = y;
                if (yy == y)
                {
                    if (0 <= yy && yy < 202)
                    {
                        if (c[x][yy])
                            --ans;
                    }
                }
            }
        }
    }
    cout << ans / 3 << endl;
    return 0;
}