#include <bits/stdc++.h>

using namespace std;

struct t
{
    int x, y;
};

t a[100000];

bool cmp(t a, t b)
{
    return a.x < b.x || a.x == b.x && a.y > b.y;
}

int main()
{
    int n, s;
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (a[i].x < s)
            s += a[i].y;
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}