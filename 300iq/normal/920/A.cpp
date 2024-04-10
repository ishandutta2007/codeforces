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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector <int> x(k);
        for (int i = 0; i < k; i++)
        {
            cin >> x[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int ans = 1e9;
            for (int a : x) ans = min(ans, abs(i - a));
            res = max(res, ans);
        }
        cout << res + 1 << '\n';
    }
}