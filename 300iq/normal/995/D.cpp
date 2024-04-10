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
    int n, r;
    cin >> n >> r;
    vector <int> d(1 << n);
    ll ans = 0;
    int x;
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> x;
        d[i] = x;
        ans += d[i];
    }
    int ret = (1 << n);
    cout << fixed << setprecision(20) << ans / (long double) ret << '\n';
    while (r--)
    {
        int z, g;
        cin >> z >> g;
        ans -= d[z];
        d[z] = g;
        ans += d[z];
        cout << fixed << setprecision(20) << ans / (long double) ret << '\n';
    }
}