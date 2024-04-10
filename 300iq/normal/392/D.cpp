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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 7;
const int inf = 1e9 + 7;

int a[3][N];
int ind[N][3];

multiset <pair <int, int> > q;
multiset <int> val;

void add(int i)
{
    pair <int, int> x = {ind[i][1] - 1, ind[i][2]};
    auto it = q.lower_bound(x);
    if (it != q.end() && it->second >= x.second)
    {
        return;
    }
    while (!q.empty())
    {
        auto it = q.upper_bound(x);
        if (it == q.begin()) break;
        it--;
        if (it->second <= x.second)
        {
            int my_first = 0;
            if (it != q.begin())
            {
                my_first = prev(it)->first + 1;
            }
            if (next(it) != q.end())
            {
                int _x = next(it)->first, _y = next(it)->second;
                val.erase(val.find(it->first + 1 + _y));
                val.insert(my_first + _y);
            }
            val.erase(val.find(my_first + it->second));
            q.erase(it);
        }
        else
        {
            break;
        }
    }
    int my_first = 0;
    q.insert(x);
    it = q.find(x);
    if (it != q.begin())
    {
        my_first = prev(it)->first + 1;
    }
    if (next(it) != q.end())
    {
        int _x = next(it)->first, _y = next(it)->second;
        val.erase(val.find(my_first + _y));
        val.insert(x.first + 1 + _y);
    }    
    val.insert(my_first + x.second);
}

int get()
{
    if (q.empty())
    {
        return 0;
    }
    else
    {
        int ret = q.rbegin()->first + 1;
        ret = min(ret, *val.begin());
        return ret;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> p;
    for (int t = 0; t < 3; t++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[t][i];
            p.push_back(a[t][i]);
        }
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    int m = (int) p.size();
    int sz = 0;
    for (int i = 0; i < m; i++)
    {
        for (int t = 0; t < 3; t++)
        {
            ind[i][t] = inf + sz;
            sz++;
        }
    }
    for (int t = 0; t < 3; t++)
    {
        for (int i = 0; i < n; i++)
        {
            a[t][i] = lower_bound(p.begin(), p.end(), a[t][i]) - p.begin();
            ind[a[t][i]][t] = min(ind[a[t][i]][t], i + 1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (ind[i][0] >= inf)
        {
            add(i);
        }
    }
    int ans = n + get();
    for (int i = n - 1; i >= 0; i--)
    {
        int val = a[0][i];
        if (ind[val][0] == i + 1)
        {
            add(val);
        }
        ans = min(ans, i + get());
    }
    cout << ans << '\n';
}