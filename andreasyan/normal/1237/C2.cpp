#include <bits/stdc++.h>
using namespace std;
const int N = 50004;
struct ban
{
    int i;
    int x, y, z;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    if (a.y < b.y)
        return true;
    if (a.y > b.y)
        return false;
    return a.z < b.z;
}
 
int n;
ban a[N];
 
bool c[N];
 
vector<ban> v;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int vs = v.size();
    for (int i = 0; i < vs - 1; ++i)
    {
        if (v[i].x == v[i + 1].x && v[i].y == v[i + 1].y)
        {
            if (!c[v[i].i] && !c[v[i + 1].i])
            {
                printf("%d %d\n", v[i].i, v[i + 1].i);
                c[v[i].i] = c[v[i + 1].i] = true;
            }
        }
    }
    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    vs = v.size();
    for (int i = 0; i < vs - 1; ++i)
    {
        if (v[i].x == v[i + 1].x)
        {
            if (!c[v[i].i] && !c[v[i + 1].i])
            {
                printf("%d %d\n", v[i].i, v[i + 1].i);
                c[v[i].i] = c[v[i + 1].i] = true;
            }
        }
    }
    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    vs = v.size();
    for (int i = 0; i < vs - 1; ++i)
    {
        if (!c[v[i].i] && !c[v[i + 1].i])
        {
            printf("%d %d\n", v[i].i, v[i + 1].i);
            c[v[i].i] = c[v[i + 1].i] = true;
        }
    }
    return 0;
}