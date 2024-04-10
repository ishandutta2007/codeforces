#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int x, d;
    ban(){}
    ban(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};

int n, m;
int a[N];

set<int> s;

long long ans;
int yans[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        s.insert(a[i]);
    }
    queue<ban> q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(ban(a[i] + 1, 1));
        q.push(ban(a[i] - 1, 1));
    }
    for (int i = 0; i < m; ++i)
    {
        while (1)
        {
            ban t = q.front();
            q.pop();
            if (s.find(t.x) != s.end())
                continue;
            s.insert(t.x);
            ans += t.d;
            yans[i] = t.x;
            q.push(ban(t.x + 1, t.d + 1));
            q.push(ban(t.x - 1, t.d + 1));
            break;
        }
    }
    printf("%lld\n", ans);
    for (int i = 0; i < m; ++i)
        printf("%d ", yans[i]);
    printf("\n");
    return 0;
}