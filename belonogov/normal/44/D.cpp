#include <iostream>
#include <cmath>

using namespace std;
struct point
{
    int x, y, z;
};
point a[5002];
long double dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}

int main()
{
    long double x, ans = 1e7;
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            x = dist(a[0], a[i]) + dist(a[0], a[j]) + dist(a[i], a[j]);
            if (i != j && x < ans)
                ans = x;
        }
    }
    cout.precision(15);
    cout << fixed << ans / 2;
    return 0;
}