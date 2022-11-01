#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct point
{
    int x, y;
};

bool cmp(point b, point c)
{
    return ((abs(b.x) + abs(b.y)) < (abs(c.x) + abs(c.y)));
}

point a[10000000];

int main()
{
    int n;
    int qua = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].x, &a[i].y);
        if (a[i].x != 0)
            qua += 2;
        if (a[i].y != 0)
            qua += 2;
        qua += 2;
    }
    cout << qua << endl;
    sort (a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        int x = a[i].x;
        int y = a[i].y;
        if (a[i].x > 0)
            cout << "1 " << x << " R" << endl;
        if (a[i].x < 0)
            cout << "1 " << -x << " L" << endl;
        if (a[i].y > 0)
            cout << "1 " << y << " U" << endl;
        if (a[i].y < 0)
            cout << "1 " << -y << " D" << endl;
        cout << 2 << endl;
        if (a[i].x > 0)
            cout << "1 " << x << " L" << endl;
        if (a[i].x < 0)
            cout << "1 " << -x << " R" << endl;
        if (a[i].y > 0)
            cout << "1 " << y << " D" << endl;
        if (a[i].y < 0)
            cout << "1 " << -y << " U" << endl;
        cout << 3 << endl;
    }
    return 0;
}