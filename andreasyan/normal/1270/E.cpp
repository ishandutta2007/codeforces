#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;
struct ban
{
    int x, y;
    ban()
    {
        x = y = 0;
    }
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int n;
ban b[N];
vector<pair<ban, int> > a[2][2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &b[i].x, &b[i].y);
    }
    int minx = b[1].x;
    int miny = b[1].y;
    for (int i = 1; i <= n; ++i)
    {
        minx = min(minx, b[i].x);
        miny = min(miny, b[i].y);
    }
    for (int i = 1; i <= n; ++i)
    {
        b[i].x -= minx;
        b[i].y -= miny;
    }
    for (int i = 1; i <= n; ++i)
    {
        a[b[i].x % 2][b[i].y % 2].push_back(m_p(b[i], i));
    }
    vector<int> ans;
    while (1)
    {
        if (a[0][0].size() + a[1][1].size() > 0)
        {
            if (a[0][1].size() + a[1][0].size() > 0)
            {
                for (int i = 0; i < a[0][0].size(); ++i)
                    ans.push_back(a[0][0][i].second);
                for (int i = 0; i < a[1][1].size(); ++i)
                    ans.push_back(a[1][1][i].second);
            }
        }
        if (!ans.empty())
            break;
        if (a[1][1].size() > 0)
        {
            if (a[0][0].size() > 0)
            {
                for (int i = 0; i < a[0][0].size(); ++i)
                    ans.push_back(a[0][0][i].second);
            }
        }
        if (!ans.empty())
            break;
        if (a[0][1].size() > 0)
        {
            if (a[1][0].size() > 0)
            {
                for (int i = 0; i < a[0][1].size(); ++i)
                    ans.push_back(a[0][1][i].second);
            }
        }
        if (!ans.empty())
            break;
        int x, y;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                if (!a[i][j].empty())
                {
                    x = i;
                    y = j;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            b[i].x = (b[i].x + x) / 2;
            b[i].y = (b[i].y + y) / 2;
        }
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
                a[i][j].clear();
        }
        for (int i = 1; i <= n; ++i)
        {
            a[b[i].x % 2][b[i].y % 2].push_back(m_p(b[i], i));
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}