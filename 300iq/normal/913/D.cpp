#include <cmath>
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
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 2e5 + 7;

int n, t;

vector <pair <int, int> > pos[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        int x, t;
        scanf("%d%d", &x, &t);
        pos[x].push_back({t, i});
    }
    set <pair <int, int> > s;
    ll sum_time = 0;
    for (int i = n; i >= 0; i--)
    {
        for (auto p : pos[i])
        {
            int x = p.first, ind = p.second;
            s.insert({x, ind});
            sum_time += x;
            while ((int) s.size() > i)
            {
                sum_time -= s.rbegin()->first;
                s.erase(--s.end());
            }
        }
        while ((int) s.size() > i)
        {
            sum_time -= s.rbegin()->first;
            s.erase(--s.end());
        }
        if ((int) s.size() == i && sum_time <= t)
        {
            printf("%d\n", i);
            printf("%d\n", i);
            for (auto c : s) printf("%d ", c.second + 1);
            puts("");
            return 0;
        }
    }
}