#include <bits/stdc++.h>
using namespace std;
struct ban
{
    long long x, y;
    ban()
    {
        x = y = 0;
    }
    ban(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
};

long long dist(ban a, ban b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ban frc(ban a, ban b)
{
    return ban(-(a.y - b.y) + b.x, (a.x - b.x) + b.y);
}

ban a[4], b[4];

int ans;

void rec(int i, int yans)
{
    if (i == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = i + 1; j < 4; ++j)
            {
                if (a[i].x == a[j].x && a[i].y == a[j].y)
                    return;
            }
        }
        int u[4] = {0, 1, 2, 3};
        do
        {
            bool z = true;
            long long aa = dist(a[u[0]], a[u[1]]);
            for (int i = 0; i < 4; ++i)
            {
                if (dist(a[u[i]], a[u[(i + 1) % 4]]) != aa)
                {
                    z = false;
                    break;
                }
                if (dist(a[u[i]], a[u[(i + 2) % 4]]) != 2 * aa)
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                ans = min(ans, yans);
                break;
            }
        } while (next_permutation(u, u + 4));
        return;
    }
    for (int j = 0; j < 4; ++j)
    {
        rec(i + 1, yans + j);
        a[i] = frc(a[i], b[i]);
    }
}

void solv()
{
    for (int i = 0; i < 4; ++i)
    {
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    }
    ans = 100;
    rec(0, 0);
    if (ans == 100)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}