#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 3003;
const int INF = 1000000009;
struct ban
{
    int i;
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x - a.y > b.x - b.y;
}

int n, q1, q2;
ban a[N];

int p[N], s[N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d%d%d", &n, &q1, &q2);
    for (int i = 1; i <= n; ++i)
        a[i].i = i;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].x);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].y);
    sort(a + 1, a + n + 1);
    priority_queue<int> q;
    int yans = 0;
    if (q.size() < q1)
        p[0] = -INF;
    else
        p[0] = yans;
    for (int i = 1; i <= n; ++i)
    {
        q.push(-a[i].x);
        yans += a[i].x;
        if (q.size() > q1)
        {
            yans += q.top();
            q.pop();
        }
        if (q.size() < q1)
            p[i] = -INF;
        else
            p[i] = yans;
    }
    while (!q.empty())
        q.pop();
    yans = 0;
    if (q.size() < q2)
        s[n + 1] = -INF;
    else
        s[n + 1] = yans;
    for (int i = n; i >= 1; --i)
    {
        q.push(-a[i].y);
        yans += a[i].y;
        if (q.size() > q2)
        {
            yans += q.top();
            q.pop();
        }
        if (q.size() < q2)
            s[i] = -INF;
        else
            s[i] = yans;
    }
    for (int i = 1; i <= n; ++i)
        p[i] = max(p[i], p[i - 1]);
    for (int i = n; i >= 1; --i)
        s[i] = max(s[i], s[i + 1]);
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, p[i] + s[i + 1]);
    printf("%d\n", ans);
    for (int i = 0; i <= n; ++i)
    {
        if (p[i] + s[i + 1] == ans)
        {
            vector<pair<int, int> > v;
            for (int j = 1; j <= i; ++j)
            {
                v.push_back(m_p(a[j].x, a[j].i));
            }
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            for (int i = 0; i < q1; ++i)
                printf("%d ", v[i].second);
            printf("\n");
            v.clear();
            for (int j = i + 1; j <= n; ++j)
            {
                v.push_back(m_p(a[j].y, a[j].i));
            }
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            for (int i = 0; i < q2; ++i)
                printf("%d ", v[i].second);
            printf("\n");
            return 0;
        }
    }
    return 0;
}