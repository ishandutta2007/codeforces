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
#include <iomanip>

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int n, w;
    cin >> n >> w;
    vector <int> a(n);
    vector <pair <int, int> > e;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        e.push_back({a[i], i});
    }
    sort(e.rbegin(), e.rend());
    int ind = max_element(a.begin(), a.end()) - a.begin();
    for (auto &c : e)
    {
        w -= c.first / 2 + c.first % 2;
        c.first = c.first / 2 + c.first % 2;
    }
    if (w < 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (auto &c : e)
        {
            int can_add = min(a[c.second] - c.first, w);
            w -= can_add;
            c.first += can_add;
            a[c.second] = c.first;
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}