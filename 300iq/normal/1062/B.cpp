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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    int mx = 0;
    vector <int> ret;
    int d = 0;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            ret.push_back(cnt);
            while ((1 << d) < cnt) d++;
            ans *= i;
        }
    }
    int as = 0;
    for (int x : ret)
    {
        if ((1 << d) != x)
        {
            as = 1;
        }
    }
    cout << ans << ' ' << as + d << '\n';
}