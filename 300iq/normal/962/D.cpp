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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map <ll, set <int> > s;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    for (auto c : s)
    {
        while ((int) c.second.size() >= 2)
        {
            int x = *c.second.begin();
            int y = *next(c.second.begin());
            a[y] += a[x];
            a[x] = -1;
            c.second.erase(x);
            c.second.erase(y);
            s[a[y]].insert(y);
        }
    }
    vector <ll> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1) ans.push_back(a[i]);
    }
    cout << ans.size() << '\n';
    for (ll x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
}