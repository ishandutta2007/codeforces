
/*
   
   
   
   
   
   
   
   
   
   
*/

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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    vector <vector <int> > bit(31);
    vector <int> ST_bit(31, -1);
    vector <int> ST(n + 7, -1);
    vector <vector <int> > pos(n + 7);
    map <int, int> mp;
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (!mp.count(a[i]))
        {
            mp[a[i]] = sz++;
        }
        pos[mp[a[i]]].push_back(i);
        for (int j = 30; j >= 0; j--)
        {
            if ((a[i] >> j) & 1)
            {
                bit[j].push_back(i);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector <pair <int, int> > x;
        for (int it = 0; it <= 30; it++)
        {
            int ind = ST_bit[it];
            while (ind + 1 < (int) bit[it].size() && bit[it][ind + 1] < i)
            {
                ind++;
                ST_bit[it]++;
            }
            if (ind + 1 != (int) bit[it].size())
            {
                x.push_back({bit[it][ind + 1], it});                
            }
        }
        int st = i;
        x.push_back({n, -1});
        sort(x.begin(), x.end());
        int j = -1;
        int cur = 0;
        for (int i = 0; i < (int) x.size() - 1; i++)
        {
            if (x[i].first == x[i + 1].first)
            {
                continue;
            }
            while (j + 1 < (int) x.size() && x[j + 1].first == x[i].first)
            {
                j++;
                cur |= (1 << x[j].second);
            }
            int real = cur;
            if (mp.count(cur))
            {
                real = mp[cur];
            }
            else
            {
                real = sz + 1;
            }
            int first = x[i].first;
            int last = x[i + 1].first - 1;
            int ind = ST[real];
            while (ind + 1 < (int) pos[real].size() && pos[real][ind + 1] < st)
            {
                ind++;
                ST[real]++;
            }
            if (ind + 1 == (int) pos[real].size() || pos[real][ind + 1] > last)
            {
                ans += last - first + 1;
            }
            else
            {
                if (pos[real][ind + 1] > first)
                {
                    ans += pos[real][ind + 1] - first;
                }
            }
        }
    }
    printf("%lld\n", ans);
}