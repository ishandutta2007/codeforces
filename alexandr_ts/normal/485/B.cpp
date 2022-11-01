#include <bits/stdc++.h>

using namespace std;

typedef __int64 ll;

struct point
{
    ll x, y;
};

point a[100000];

bool cmpx(point a, point b)
{
    return a.x < b.x;
}

bool cmpy(point a, point b)
{
    return a.y < b.y;
}

int main()
{
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmpx);
    ll ans = abs(a[0].x - a[n - 1].x);
    sort(a, a + n, cmpy);
    ans = max(ans, abs(a[0].y - a[n - 1].y));
    cout << (ans)*(ans);
}