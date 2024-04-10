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
    vector <int> a(n);
    set <int> q;
    q.insert(1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        if (i != 0)
        {
            if (a[i] == a[i - 1])
            {
                cout << "NO\n";
                return 0;
            }
            q.insert(abs(a[i] - a[i - 1]));
        }
    }
    if (q.size() > 2)
    {
        cout << "NO\n";
        return 0;
    }
    int x = (int) 1e9, y = (int) *q.rbegin();
    int f = a[0] / y, s = a[0] % y;
    for (int i = 0; i < n; i++)
    {
        int _f = a[i] / y, _s = a[i] % y;
        if (0 <= _f && _f < x && 0 <= _s && _s < y && (i == 0 || abs(f - _f) + abs(s - _s) == 1))
        {
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
        f = _f, s = _s;
    }
    cout << "YES\n";
    cout << x << ' ' << y << '\n';
}