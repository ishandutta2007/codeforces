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
    int n, p;
    cin >> n >> p;
    ll sum = 0;
    ll ans = 0;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll x = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        x += a[i];
        sum -= a[i];
        ans = max(ans, x % p + sum % p);
    }
    cout << ans << '\n';
}