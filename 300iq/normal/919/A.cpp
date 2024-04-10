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

bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.first * (ll) b.second < a.second * (ll) b.first;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    double ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans = min(ans, a / (double) b * m);
    }
    cout << fixed << setprecision(20) << ans << '\n';
}