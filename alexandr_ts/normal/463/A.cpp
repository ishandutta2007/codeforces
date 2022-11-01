#include <bits/stdc++.h>

using namespace std;

struct tn
{
    int x, y;
};

tn a[100000];

bool cmp(tn a, tn b)
{
    return a.y < b.y;
}

int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        if (a[i].y == 0)
            a[i].y = 200;
    }
    sort (a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (a[i].y == 200)
            a[i].y = 0;
        if (s * 100 >= a[i].x * 100 + a[i].y)
        {
            cout << (100 - a[i].y) % 100;
            return 0;
        }
    }
    cout << -1;
    return 0;
}