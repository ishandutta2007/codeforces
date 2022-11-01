#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;

struct tmp
{
    int x, y;
};

bool cmp(tmp a, tmp b)
{
    return a.x > b.x;
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    tmp a, b;
    cin >> a.x >> a.y;
    tmp c = {(abs(a.x) + abs(a.y)) * (a.x / abs(a.x)), 0};
    tmp d = {0, (abs(a.y) + abs(a.x)) * (a.y / abs(a.y))};
    if (c.x > d.x)
        swap(c, d);
    cout << c.x << " " << c.y << " " << d.x << " " << d.y;
}