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
    int n, a, b;
    cin >> n >> a >> b;
    map <ll, int> mp;
    map <pair <ll, ll>, int> mp_x;
    map <pair <ll, ll>, int> mp_y;
    map <pair <ll, pair <ll, ll> >, int> mp_xy;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x, dx, dy;
        cin >> x >> dx >> dy;
        ll ret = dy - dx * (ll) a;
        ans += mp[ret];
        ans -= mp_x[{ret, dx}];
        ans -= mp_y[{ret, dy}];
        ans += mp_xy[{ret, {dx, dy}}];
        mp[ret]++;
        mp_x[{ret, dx}]++;
        mp_y[{ret, dy}]++;
        mp_xy[{ret, {dx, dy}}]++;
    }
    cout << 2 * ans << '\n';
}