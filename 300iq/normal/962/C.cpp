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
    string s;
    cin >> s;
    int len = (int) s.size();
    int n = len;
    int lim = (1 << len);
    int ans = -1;
    for (int mask = 1; mask < lim; mask++)
    {
        string t = "";
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                t += s[i];
            }
        }
        if (t[0] != '0')
        {
            int cur = 0;
            for (auto c : t) cur = cur * 10 + c - '0';
            int x = sqrt(cur);
            while (x * x < cur) x++;
            while (x * x > cur) x--;
            if (x * x == cur)
            {
                ans = max(ans, (int) t.size());
            }
        }
    }
    if (ans == -1)
    {
        cout << ans << '\n';
    }
    else
    {
        cout << n - ans << '\n';
    }
}