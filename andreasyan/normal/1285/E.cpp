#include <bits/stdc++.h>
using namespace std;
const int N = 400005, INF = 1000000009;
struct ban
{
    int x, z;
    int i;
    ban(){}
    ban(int x, int z)
    {
        this->x = x;
        this->z = z;
    }
    ban(int x, int z, int i)
    {
        this->x = x;
        this->z = z;
        this->i = i;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.z < b.z;
}

int n;
int l[N], r[N];
int ll[N], rr[N];

vector<ban> v;
int p[N];
int p1[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &l[i], &r[i]);
    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(ban(l[i], 1, i));
        v.push_back(ban(r[i] + 1, -1, i));
    }
    v.push_back(ban(-INF, 0));
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i].z == 1)
            ll[v[i].i] = i;
        else
            rr[v[i].i] = i;
    }
    for (int i = 1; i < v.size(); ++i)
    {
        p[i] = p[i - 1] + v[i].z;
    }
    for (int i = 1; i < v.size(); ++i)
    {
        p1[i] = p1[i - 1];
        if (p[i] == 1)
            ++p1[i];
    }
    int ans = 0;
    int yans = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        if (p[i] == 0)
            ++yans;
    }
    for (int i = 1; i <= n; ++i)
    {
        int yyans = yans;
        yyans += (p1[rr[i] - 1] - p1[ll[i]]);
        if (p[ll[i]] == 0)
            --yyans;
        if (p[rr[i]] == 0)
            --yyans;
        ans = max(ans, yyans);
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}