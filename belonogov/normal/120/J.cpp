#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 10;
const int K = 200;
struct point
{
    int x, y, k, i;
    long double l;
};
point a[MAXN];
bool operator < (point a, point b)
{
    return a.l < b.l;
}
long double f(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i, j, x, y, l, r, q, w;
    long double res = 1e9;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i].k = 1;
        a[i].i = i;
        if (y < 0)
        {
            y = -y;
            a[i].k += 2;
        }
        if (x < 0)
        {
            x = -x;
            a[i].k++;
        }
        a[i].x = x;
        a[i].y = y;
        a[i].l = sqrt(a[i].x*a[i].x + a[i].y*a[i].y);

    }
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        l = 0;
        r = n - 1;
        if (i > K)
            l = i - K;
        if (i + K < n - 1)
            r = i + K;
        for (j = l; j <= r; j++)
            if (i != j && res > f(a[i], a[j]))
            {
                res = f(a[i], a[j]);
                q = i;
                w = j;
            }
    }
  //  cout << f(a[1], a[3]) << "\n"; // 3,8 == 2,7
    //cout << f(a[2], a[0]) << "\n"; // 1,9 == 0, 8
    cout << a[w].i + 1  << " " << a[w].k << " " << a[q].i + 1 << " "<< 5 - a[q].k;
/*1 3 9 1

3 2 8 2*/
    return 0;
}