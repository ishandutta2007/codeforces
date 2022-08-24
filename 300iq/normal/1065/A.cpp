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
    int t;
    cin >> t;
    while (t--)
    {
        ll s, a, b, c;
        cin >> s >> a >> b >> c;
        ll cnt = s / c;
        cout << cnt / a * b + cnt << '\n';
    }
}