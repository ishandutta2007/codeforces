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
#define int ll

using namespace std;

typedef long long ll;

mt19937 rnd(228);

main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 14;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = a[i];
        vector <int> b = a;
        b[i] = 0;
        int ok = cur / 14;
        for (int j = 0; j < n; j++) b[j] += ok;
        cur %= 14;
        int x = (i + 1) % n;
        while (cur--)
        {
            b[x]++;
            x = (x + 1) % n;
        }
        int s = 0;
        for (int i = 0; i < n; i++) if (b[i] % 2 == 0) s += b[i];
        ans = max(ans, s);
    }
    cout << ans << '\n';
}