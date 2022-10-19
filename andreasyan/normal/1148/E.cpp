#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005;

int n;
int a[N], b[N];
pair<int, int> u[N];

vector<pair<pair<int, int>, int> > ans;

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        u[i] = m_p(a[i], i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(u + 1, u + n + 1);
    sort(b + 1, b + n + 1);
    stack<pair<int, int> > s;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < b[i])
        {
            s.push(m_p(u[i].second, b[i] - a[i]));
            continue;
        }
        int d = a[i] - b[i];
        while (d)
        {
            if (s.empty())
            {
                printf("NO\n");
                return;
            }
            if (s.top().second > d)
            {
                ans.push_back(m_p(m_p(s.top().first, u[i].second), d));
                s.top().second -= d;
                d = 0;
            }
            else
            {
                ans.push_back(m_p(m_p(s.top().first, u[i].second), s.top().second));
                d -= s.top().second;
                s.pop();
            }
        }
    }
    if (!s.empty())
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}