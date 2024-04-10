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

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << n << ' ' << n << '\n';
        return 0;
    }
    ll x = 0;
    while (x * (x + 1) / 2 <= m) x++;
    ll ans2 = 0;
    if (x * (x - 1) / 2 == m) ans2 = x;
    else ans2 = x + 1;
    cout << max(0ll, n - 2 * m) << ' ' << n - ans2 << '\n';
}