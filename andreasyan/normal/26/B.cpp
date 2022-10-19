#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006, INF = 1000000009;

int n;
char a[N];

deque<int> b, p;

bool stg(int q)
{
    char u[N];
    for (int i = 0; i < n; ++i)
        u[i] = a[i];
    for (int i = 0; i < q; ++i)
    {
        u[p[i]] = 0;
        u[b[b.size() - i - 1]] = 0;
    }
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        if (u[i] == '(')
            ++p;
        else if (u[i] == ')')
            --p;
        if (p < 0)
            return false;
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
            b.push_back(i);
        else
            p.push_back(i);
    }
    while (b.size() > p.size())
    {
        a[b.back()] = 0;
        b.pop_back();
    }
    while (b.size() < p.size())
    {
        a[p.front()] = 0;
        p.pop_front();
    }
    int l = 0, r = p.size();
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = p.size() * 2 - m * 2;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
    return 0;
}