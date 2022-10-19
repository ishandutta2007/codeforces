#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;
const long long r = 1000000;

int n;
vector<vector<int> > vv;
vector<int> xx, yy;

long long dist(long long x, long long y)
{
    return x * x + y * y;
}

bool ans[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (vv.size() < 2)
        {
            vv.push_back({i});
            xx.push_back(x);
            yy.push_back(y);
        }
        else
        {
            if (dist(xx[0] + x, yy[0] + y) <= r * r)
            {
                xx[0] += x;
                yy[0] += y;
                vv[0].push_back(i);
            }
            else if (dist(xx[0] - x, yy[0] - y) <= r * r)
            {
                xx[0] -= x;
                yy[0] -= y;
                ans[i] ^= true;
                vv[0].push_back(i);
            }
            else if (dist(xx[1] + x, yy[1] + y) <= r * r)
            {
                xx[1] += x;
                yy[1] += y;
                vv[1].push_back(i);
            }
            else
            {
                xx[1] -= x;
                yy[1] -= y;
                ans[i] ^= true;
                vv[1].push_back(i);
            }
        }
        if (vv.size() == 2)
        {
            if (vv[0].size() < vv[1].size())
            {
                swap(vv[0], vv[1]);
                swap(xx[0], xx[1]);
                swap(yy[0], yy[1]);
            }
            if (dist(xx[0] + xx[1], yy[0] + yy[1]) <= r * r)
            {
                xx[0] += xx[1];
                yy[0] += yy[1];
                for (int i = 0; i < vv[1].size(); ++i)
                    vv[0].push_back(vv[1][i]);
                xx.pop_back();
                yy.pop_back();
                vv.pop_back();
            }
            else if (dist(xx[0] - xx[1], yy[0] - yy[1]) <= r * r)
            {
                xx[0] -= xx[1];
                yy[0] -= yy[1];
                for (int i = 0; i < vv[1].size(); ++i)
                {
                    ans[vv[1][i]] ^= true;
                    vv[0].push_back(vv[1][i]);
                }
                xx.pop_back();
                yy.pop_back();
                vv.pop_back();
            }
        }
    }
    if (vv.size() == 2)
    {
        if (dist(xx[0] + xx[1], yy[0] + yy[1]) > dist(xx[0] - xx[1], yy[0] - yy[1]))
        {
            for (int i = 0; i < vv[1].size(); ++i)
                ans[vv[1][i]] ^= true;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i])
            printf("1 ");
        else
            printf("-1 ");
    }
    printf("\n");
    return 0;
}