#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;
struct ban
{
    int i;
    long long t;
    ban(){}
    ban(long long t, int i)
    {
        this->i = i;
        this->t = t;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.t > b.t)
        return true;
    if (a.t < b.t)
        return false;
    return a.i > b.i;
}

int n, b;
int d[N];
priority_queue<ban> qq;
queue<int> q;

long long ans[N];

int main()
{
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%d%d", &t, &d[i]);
        qq.push(ban(t, i));
    }
    bool z = false;
    while (!qq.empty())
    {
        ban u = qq.top();
        qq.pop();
        if (u.i > 0)
        {
            if (!z && q.empty())
            {
                ans[u.i] = u.t + d[u.i];
                qq.push(ban(u.t + d[u.i], -u.i));
                z = true;
                continue;
            }
            if (q.size() == b)
            {
                ans[u.i] = -1;
                continue;
            }
            q.push(u.i);
        }
        else
        {
            z = false;
        }
        if (!z && !q.empty())
        {
            int i = q.front();
            q.pop();
            ans[i] = u.t + d[i];
            qq.push(ban(u.t + d[i], -i));
            z = true;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}