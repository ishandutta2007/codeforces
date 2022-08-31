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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

vector <pair <int, int> > solve(int l, vector <int> d)
{
    if ((int) d.size() == 0)
    {
        return {};
    }
    if ((int) d.size() == 1)
    {
        int cnt = d[0];
        vector <pair <int, int> > res;
        for (int i = 0; i <= cnt; i++)
        {
            for (int j = i + 1; j <= cnt; j++)
            {
                res.push_back({i + l, j + l});
            }
        }
        return res;
    }
    int n = (int) d.size();
    vector <pair <int, int> > ans;
    for (int i = 0; i < d[0]; i++)
    {
        for (int j = i + 1; j <= d[n - 1]; j++)
        {
            ans.push_back({l + i, l + j});
        }
    }
    vector <int> nd = d;
    for (int i = 1; i < (int) nd.size(); i++)
    {
        nd[i] -= d[0];
    }
    nd.erase(nd.begin());
    nd.pop_back();
    auto get = solve(l + d[0], nd);
    for (auto c : get) ans.push_back(c);
    return ans;
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
    vector <int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    vector <pair <int, int> > ans = solve(1, d);
    cout << ans.size() << '\n';
    for (auto c : ans)
    {
        cout << c.first << ' ' << c.second << '\n';
    }
}