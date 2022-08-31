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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <pair <int, int> > e;
    vector <int> first(3, -1);
    vector <int> last(3, -1);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        char c;
        scanf(" %c", &c);
        int t = (c == 'R' ? 1 : c == 'G' ? 0 : 2);
        if (first[t] == -1) first[t] = i;
        last[t] = i;
        e.push_back({x, t});
    }
    vector <int> ind;
    for (int i = 0; i < n; i++)
    {
        if (e[i].second == 0)
        {
            ind.push_back(i);
        }
    }
    if (first[0] == -1)
    {
        ll ret = 0;
        for (int t = 1; t <= 2; t++)
        {
            if (last[t] != -1)
            {
                ret += abs(e[last[t]].first - e[first[t]].first);
            }
        }
        printf("%lld\n", ret);
        return 0;
    }
    ll ans = 0;
    for (int t = 1; t <= 2; t++)
    {
        if (last[t] > last[0] && last[0] != -1)
        {
            ans += e[last[t]].first - e[last[0]].first;
        }
        if (first[t] < first[0] && first[t] != -1)
        {
            ans += abs(e[first[t]].first - e[first[0]].first);
        }
    }
    for (int i = 0; i + 1 < (int) ind.size(); i++)
    {
        ll len = e[ind[i + 1]].first - e[ind[i]].first;
        vector <ll> mx(3, 0);
        vector <int> prev(3, -1);
        for (int j = ind[i] + 1; j < ind[i + 1]; j++)
        {
            if (prev[e[j].second] != -1)
            {
                mx[e[j].second] = max(mx[e[j].second], (ll) (e[j].first - e[prev[e[j].second]].first));
            }
            else
            {
                mx[e[j].second] = max(mx[e[j].second], (ll) e[j].first - e[ind[i]].first);
            }
            prev[e[j].second] = j;
        }
        for (int t = 1; t <= 2; t++)
        {
            if (prev[t] != -1)
            {
                mx[t] = max(mx[t], (ll) e[ind[i + 1]].first - e[prev[t]].first);
            }
            else
            {
                mx[t] = len;
            }
        }
        ans += min(2 * len, 3 * len - mx[1] - mx[2]);
    }
    printf("%lld\n", ans);
}