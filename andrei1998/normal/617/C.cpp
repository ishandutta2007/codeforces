#include <iostream>

#define lint long long int
using namespace std;

struct point {
    int x, y;

    point(int _x = 0, int _y = 0): x(_x), y(_y) {}
} v[2005];

lint dist(const point &a, const point &b) {
    return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}

int main()
{
    int n = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i].x >> v[i].y;

    //Daca nu folosim prima fantana deloc
    v[0] = point(x1, y1);

    lint ans = 1e18;
    for (int i = 0; i <= n; ++ i) {
        lint second = 0;
        for (int j = 1; j <= n; ++ j)
            if (dist(point(x1, y1), v[j]) > dist(point(x1, y1), v[i]))
                if (dist(point(x2, y2), v[j]) > second)
                    second = dist(point(x2, y2), v[j]);

        if (dist(point(x1, y1), v[i]) + second < ans)
            ans = dist(point(x1, y1), v[i]) + second;
    }

    cout << ans << '\n';
    return 0;
}