#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
#define m_p make_pair

int q, x;
int u[N];

int main()
{
    scanf("%d%d", &q, &x);
    set<pair<int, int> > s;
    for (int i = 0; i < x; ++i)
        s.insert(m_p(u[i], i));
    while (q--)
    {
        int y;
        scanf("%d", &y);
        y %= x;
        s.erase(m_p(u[y], y));
        ++u[y];
        s.insert(m_p(u[y], y));
        pair<int, int> ans = *s.begin();
        printf("%d\n", ans.first * x + ans.second);
    }
    return 0;
}