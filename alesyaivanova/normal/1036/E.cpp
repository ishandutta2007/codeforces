#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}

    point operator-(point b)
    {
        return {x - b.x, y - b.y};
    }

    long long operator*(point b)
    {
        return x * 1ll * b.y - y * 1ll * b.x;
    }
};

point p[2010];
int n;
map<pair<int, int>, int> m;

bool per(point a, point b, point c, point d)
{
    bool t1 = ((c - a) * (b - a) >= 0);
    bool t2 = ((b - a) * (d - a) >= 0);

    bool k1 = ((c - a) * (b - a) <= 0);
    bool k2 = ((b - a) * (d - a) <= 0);

    bool t3 = ((a - d) * (c - d) >= 0);
    bool t4 = ((c - d) * (b - d) >= 0);

    bool k3 = ((a - d) * (c - d) <= 0);
    bool k4 = ((c - d) * (b - d) <= 0);

    return ((t1 & t2) | (k1 & k2)) & ((t3 & t4) | (k3 & k4));
}

bool check(point a, point b, point c, point d, point k)
{
    bool t1 = ((c - d) * (a - c) >= 0);
    bool t2 = ((c - d) * (k - c) >= 0);

    bool k1 = ((c - d) * (a - c) <= 0);
    bool k2 = ((c - d) * (k - c) <= 0);

    bool t3 = ((c - d) * (b - c) >= 0);
    bool t4 = ((c - d) * (k - c) <= 0);

    bool k3 = ((c - d) * (b - c) <= 0);
    bool k4 = ((c - d) * (k - c) >= 0);

    return ((t1 & t2) | (k1 & k2)) & ((t3 & t4) | (k3 & k4));
}

int gcd(int a, int b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < 2 * n; i += 2)
        cin >> p[i].x >> p[i].y >> p[i + 1].x >> p[i + 1].y;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        point a = p[i * 2];
        point b = p[i * 2 + 1];
        int g = gcd(abs(b.x - a.x), abs(b.y - a.y));
        ans += g + 1;
        for (int e = i + 1; e < n; e++)
        {
            point c = p[e * 2];
            point d = p[e * 2 + 1];
            if (!per(a, b, c, d))
                continue;
            int x1 = (b.x - a.x) / g;
            int y1 = (b.y - a.y) / g;
            int left = 0;
            int right = g + 1;
            while (right - left > 1)
            {
                int m = (left + right) / 2;
                point k{x1 * m + a.x, y1 * m + a.y};
                if (check(a, b, c, d, k))
                    left = m;
                else
                    right = m;
            }
            point k{x1 * left + a.x, y1 * left + a.y};
            if ((c - d) * (k - c) == 0)
                m[make_pair(k.x, k.y)]++;
        }
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        long long a = (*i).second;
        long long d = 1 + 8 * a;
        long long d1 = sqrt(d);
        if ((d1 + 1) * (d1 + 1) == d)
            d1++;
        else if ((d1 - 1) * (d1 - 1) == d)
            d1--;
        ans -= (1 + d1) / 2 - 1;
    }
    cout << ans;
}