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

map <int, vector <int> > ret;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int bal = 0;
        int mn = 0;
        for (auto c : s[i])
        {
            bal += (c == '(');
            bal -= (c == ')');
            mn = min(mn, bal);
        }
        if (bal >= 0 && mn < 0) continue;
        ret[bal].push_back(mn);
    }
    int ans = ret[0].size() / 2;
    for (int x = -500000; x < 0; x++)
    {
        int have = 0;
        for (int y : ret[x])
        {
            if (-x + y >= 0)
            {
                have++;
            }
        }
        ans += min(have, (int) ret[-x].size());
    }
    cout << ans << '\n';
}