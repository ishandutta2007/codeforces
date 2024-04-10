#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int x, y, z;
};
bool operator<(const ban& a, const ban& b)
{
    return a.z < b.z;
}

int n, m;
ban a[N];

int p[N];
int q[N];
int qq[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
    q[y] += q[x];
    q[y]++;
    qq[y] += qq[x];
}


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a, a + m);
    for (int i = 1; i <= n; ++i)
    {
        qq[i] = 1;
        p[i] = i;
    }
    long long ans = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        int x = a[i].x;
        int y = a[i].y;
        int z = a[i].z;
        if (fi(x) != fi(y))
        {
            if (q[fi(x)] + q[fi(y)] + 1 <= qq[fi(x)] + qq[fi(y)])
            {
                ans += z;
                kpc(x, y);
            }
        }
        else
        {
            if (q[fi(x)] + 1 <= qq[fi(x)])
            {
                q[fi(x)]++;
                ans += z;
            }
        }
    }
    cout << ans << endl;
    return 0;
}