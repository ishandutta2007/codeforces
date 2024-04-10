#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n, t;
vector<pair<int, int> > a[N];

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(m_p(y, i));
    }
    int ans = 0, ansi = n + 1;
    priority_queue<int> q;
    long long tt = 0;
    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            int x = a[i][j].first;
            q.push(x);
            tt += x;
        }
        while (q.size() > i || tt > t)
        {
            tt -= q.top();
            q.pop();
        }
        if (q.size() > ans)
        {
            ans = q.size();
            ansi = i;
        }
    }
    printf("%d\n", ans);
    vector<pair<int, int> > v;
    for (int i = ansi; i <= n; ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
            v.push_back(a[i][j]);
    }
    sort(v.begin(), v.end());
    tt = 0;
    vector<int> ansp;
    for (int i = 0; i < min((int)v.size(), ansi); ++i)
    {
        tt += v[i].first;
        if (tt > t)
            break;
        ansp.push_back(v[i].second);
    }
    printf("%d\n", ansp.size());
    for (int i = 0; i < ansp.size(); ++i)
        printf("%d ", ansp[i]);
    printf("\n");
    return 0;
}