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

const int N = (1 << 22);

int cnt[N];
bool u[N];

int n, m;

vector <int> t;

void dfs(int mask)
{
    if (u[mask])
    {
        return;
    }
    u[mask] = true;
    for (int i = 0; i < n; i++)
    {
        if ((mask >> i) & 1)
        {
            dfs(mask ^ (1 << i));
        }
    }
    if (cnt[mask])
        dfs(((1 << n) - 1) ^ mask);
    t.push_back(mask);
}

int zhfs(int mask)
{
    if (u[mask])
    {
        return 0;
    }
    u[mask] = true;
    int ans = cnt[mask];
    for (int i = 0; i < n; i++)
    {
        if (!((mask >> i) & 1))
        {
            ans += zhfs(mask ^ (1 << i));
        }
    }
    if (cnt[((1 << n) - 1) ^ mask])
        ans += zhfs(((1 << n) - 1) ^ mask);
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int lim = (1 << n);
    for (int mask = 0; mask < lim; mask++)
    {
        dfs(mask);
    }
    for (int mask = 0; mask < lim; mask++)
    {
        u[mask] = 0;
    }
    reverse(t.begin(), t.end());
    int ans = 0;
    for (int x : t)
    {
        if (zhfs(x))
        {
            ans++;
        }
    }
    cout << ans << '\n';
}