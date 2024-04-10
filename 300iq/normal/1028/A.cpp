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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int xl = 1e9, xr = -1e9, yl = 1e9, yr = -1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'B')
            {
                xl = min(xl, i);
                xr = max(xr, i);
                yl = min(yl, j);
                yr = max(yr, j);
            }
        }
    }
    cout << (xl + xr) / 2 + 1 << ' ' << (yl + yr) / 2 + 1 << '\n';
}