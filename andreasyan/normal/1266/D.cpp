#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;
struct ban
{
    int i;
    long long z;
    ban()
    {
        i = 0;
        z = 0;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.z < b.z;
}

int n, m;

ban a[N];

vector<pair<pair<int, int>, long long> > ans;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        a[i].i = i;
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].z -= z;
        a[y].z += z;
    }
    sort(a + 1, a + n + 1);
    int j = n;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].z == 0)
            break;
        while (a[j].z == 0)
            --j;
        while (1)
        {
            if ((-a[i].z) > a[j].z)
            {
                ans.push_back(m_p(m_p(a[i].i, a[j].i), a[j].z));
                a[i].z += a[j].z;
                a[j].z = 0;
                --j;
            }
            else
            {
                ans.push_back(m_p(m_p(a[i].i, a[j].i), -a[i].z));
                a[j].z += a[i].z;
                a[i].z = 0;
                break;
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d %d %lld\n", ans[i].first.first, ans[i].first.second, ans[i].second);
    }
    return 0;
}