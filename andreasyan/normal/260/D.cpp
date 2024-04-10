#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

set<pair<int, int> > s[2];

int n;

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int u, d;
        scanf("%d%d", &u, &d);
        s[u].insert(m_p(d, i));
    }
    for (int ii = 0; ii < n - 1; ++ii)
    {
        if (s[0].begin()->first < s[1].begin()->first)
        {
            pair<int, int> x = *s[0].begin();
            pair<int, int> y = *(--s[1].end());
            s[0].erase(x);
            s[1].erase(y);
            printf("%d %d %d\n", x.second, y.second, x.first);
            y.first -= x.first;
            s[1].insert(y);
        }
        else if (s[0].begin()->first > s[1].begin()->first)
        {
            pair<int, int> x = *(--s[0].end());
            pair<int, int> y = *s[1].begin();
            s[0].erase(x);
            s[1].erase(y);
            printf("%d %d %d\n", x.second, y.second, y.first);
            x.first -= y.first;
            s[0].insert(x);
        }
        else
        {
            if (s[0].size() > s[1].size())
            {
                pair<int, int> x = *s[0].begin();
                pair<int, int> y = *(--s[1].end());
                s[0].erase(x);
                s[1].erase(y);
                printf("%d %d %d\n", x.second, y.second, x.first);
                y.first -= x.first;
                s[1].insert(y);
            }
            else
            {
                pair<int, int> x = *(--s[0].end());
                pair<int, int> y = *s[1].begin();
                s[0].erase(x);
                s[1].erase(y);
                printf("%d %d %d\n", x.second, y.second, y.first);
                x.first -= y.first;
                s[0].insert(x);
            }
        }
    }
    return 0;
}