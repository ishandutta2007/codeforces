#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <iomanip>

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

vector <int> t[4];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int w, c;
        scanf("%d%d", &w, &c);
        t[w].push_back(c);
    }
    for (int w = 1; w <= 3; w++)
    {
        sort(t[w].rbegin(), t[w].rend());
    }
    ll ans = 0;
    {
        vector<pair<int, int> > e;
        ll cur = (ll) -1e18;
        for (int i = 0; i < (int) t[1].size(); i += 2)
        {
            if (i + 1 < (int) t[1].size())
            {
                e.push_back({t[1][i] + t[1][i + 1], i});
            }
            else
            {
                cur = t[1][i];
            }
        }
        for (auto c : t[2])
        {
            e.push_back({c, -1});
        }
        sort(e.rbegin(), e.rend());
        int sz = (int) t[3].size();
        int j = -1;
        int k = -1;
        int sum = 0;
        int sem = 0;
        ll c1 = 0, c2 = 0;
        for (int i = 0; i < (int) e.size(); i++)
        {
            sum += 2;
            sem += 2;
            c1 += e[i].first;
            c2 += e[i].first;
        }
        for (int i = (int) e.size() - 1; i >= -1; i--)
        {
            while (j + 1 < sz && sum + 3 <= m)
            {
                j++;
                c1 += t[3][j];
                sum += 3;
            }
            while (k + 1 < sz && sem + 3 <= m - 1)
            {
                k++;
                c2 += t[3][k];
                sem += 3;
            }
            if (sum <= m)
            {
                ans = max(ans, c1);
            }
            if (sem + 1 <= m)
            {
                ans = max(ans, c2 + cur);
            }
            if (i == -1)
            {
                break;
            }
            if (e[i].second != -1)
            {
                cur = max(cur, (ll) t[1][e[i].second]);
            }
            sum -= 2, sem -= 2;
            c1 -= e[i].first, c2 -= e[i].first;
        }
    }
    if (t[1].size())
    {
        vector <pair<int, int> > e;
        ll cur = t[1][0];
        t[1].erase(t[1].begin());
        for (int i = 0; i < (int) t[1].size(); i += 2)
        {
            if (i + 1 < (int) t[1].size())
            {
                e.push_back({t[1][i] + t[1][i + 1], i});
            }
            else
            {
                cur = max(cur, (ll) t[1][i]);
            }
        }
        for (auto c : t[2])
        {
            e.push_back({c, -1});
        }
        sort(e.rbegin(), e.rend());
        int sz = (int) t[3].size();
        int j = -1;
        int k = -1;
        int sum = 0;
        int sem = 0;
        ll c1 = 0, c2 = 0;
        for (int i = 0; i < (int) e.size(); i++)
        {
            sum += 2;
            sem += 2;
            c1 += e[i].first;
            c2 += e[i].first;
        }
        for (int i = (int) e.size() - 1; i >= -1; i--)
        {
            while (j + 1 < sz && sum + 3 <= m)
            {
                j++;
                c1 += t[3][j];
                sum += 3;
            }
            while (k + 1 < sz && sem + 3 <= m - 1)
            {
                k++;
                c2 += t[3][k];
                sem += 3;
            }
            if (sum <= m)
            {
                ans = max(ans, c1);
            }
            if (sem + 1 <= m)
            {
                ans = max(ans, c2 + cur);
            }
            if (i == -1)
            {
                break;
            }
            if (e[i].second != -1)
            {
                cur = max(cur, (ll) t[1][e[i].second]);
            }
            sum -= 2, sem -= 2;
            c1 -= e[i].first, c2 -= e[i].first;
        }
    }
    printf("%lld\n", ans);
}