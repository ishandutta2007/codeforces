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

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

set <pair <int, int> > ans;

int n;
int as = 0;
vector <int> ret;

void rec(int cur, int score)
{
    ret.push_back(cur);
    as = max(as, score);
    for (int i = -n; i <= n; i++)
    {
        if (abs(i) >= 2)
        {
            if ((i % cur == 0 || cur % i == 0) && !ans.count({i, cur}) && abs(i) != abs(cur))
            {
                ans.insert({i, cur});
                ans.insert({cur, i});
                score += max(abs(cur), abs(i)) / min(abs(cur), abs(i));
                rec(i, score);
                score -= max(abs(cur), abs(i)) / min(abs(cur), abs(i));
                ans.erase({i, cur});
                ans.erase({cur, i});
            }
        }
    }
    ret.pop_back();
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
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + i; j <= n; j += i)
        {
            ans += j / i;
        }
    }
    cout << ans * 4 << '\n';
    return 0;
    /*
    for (n = 2; n <= 100; n++)
    {
        as = 0;
        vector <int> lim;
        for (int i = -n; i <= n; i++)
        {
            if (abs(i) >= 2)
            {
                lim.push_back(i);
                rec(i, 0);
            }
        }
        int sum = 0;
        for (int x : lim)
        {
            for (int y : lim)
            {
                if ((x % y == 0 || y % x == 0) && abs(x) != abs(y)) sum += max(abs(x), abs(y)) / min(abs(x), abs(y));
            }
        }
        cout << as << ' ' << sum << '\n';
    }
    */
}