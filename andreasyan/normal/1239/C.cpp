#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    int ty;
    int i;
    long long t;
    ban(){}
    ban(int ty, int i, long long t)
    {
        this->ty = ty;
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
    if (a.ty < b.ty)
        return true;
    if (a.ty > b.ty)
        return false;
    return a.i > b.i;
}

int n, p;
priority_queue<ban> q;

long long ans[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        q.push(ban(2, i, x));
    }
    set<int> s;
    set<int> sq;
    long long qt = 0;
    while (!q.empty())
    {
        ban u = q.top();
        q.pop();
        if (u.ty == 2)
        {
            if (sq.empty() || u.i < (*sq.begin()))// && (s.empty() || u.i < (*s.begin())))
            {
                qt = max(qt + p, u.t + p);
                q.push(ban(1, u.i, qt));
                sq.insert(u.i);
            }
            else
                s.insert(u.i);
        }
        else
        {
            ans[u.i] = u.t;
            sq.erase(u.i);
            if (!s.empty() && (sq.empty() || (*s.begin()) < (*sq.begin())))
            {
                qt = max(qt + p, u.t + p);
                q.push(ban(1, (*s.begin()), qt));
                sq.insert(*s.begin());
                s.erase(s.begin());
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}