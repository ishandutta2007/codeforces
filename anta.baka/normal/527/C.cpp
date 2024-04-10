#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int w, h, n;
set<int> x, y;
char t[200000];
int d[200000];
int xb, yb;
ll ans[200000];

int main()
{
    scanf("%d%d%d", &w, &h, &n);
    x.insert(0); x.insert(w);
    y.insert(0); y.insert(h);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c %d", &t[i], &d[i]);
        if(t[i] == 'H') y.insert(d[i]);
        else x.insert(d[i]);
    }
    for(auto it = x.begin(); it != x.end(); it++)
    {
        if(it == x.begin()) continue;
        auto p = it; p--;
        xb = max(xb, *it - *p);
    }
    for(auto it = y.begin(); it != y.end(); it++)
    {
        if(it == y.begin()) continue;
        auto p = it; p--;
        yb = max(yb, *it - *p);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        ans[i] = 1LL * xb * yb;
        if(t[i] == 'H')
        {
            auto me = y.find(d[i]);
            auto i1 = me, i2 = me;
            i1--; i2++;
            yb = max(yb, *i2 - *i1);
            y.erase(me);
        }
        else
        {
            auto me = x.find(d[i]);
            auto i1 = me, i2 = me;
            i1--; i2++;
            xb = max(xb, *i2 - *i1);
            x.erase(me);
        }
    }
    for(int i = 0; i < n; i++) printf("%I64d\n", ans[i]);
}