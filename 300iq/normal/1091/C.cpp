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
    vector <int> a;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            a.push_back(i);
            if (i * i != n)
            {
                a.push_back(n / i);
            }
        }
    }
    vector <ll> ret;
    for (int x : a)
    {
        ret.push_back(x * (ll) (x - 1) / 2 * (n / x) + x);
    }
    sort(ret.begin(), ret.end());
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
    for (ll x : ret) cout << x << ' ';
    cout << endl;
}