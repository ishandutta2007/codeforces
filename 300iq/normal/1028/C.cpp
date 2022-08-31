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

struct rect
{
    int x1, y1, x2, y2;
};

rect inter(const rect &a, const rect &b)
{
    return {max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <rect> a;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({x1, y1, x2, y2});
    }
    vector <rect> pref;
    rect cur;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cur = a[i];
        }
        else
        {
            cur = inter(cur, a[i]);
        }
        pref.push_back(cur);
    }
    vector <rect> suf;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            cur = a[i];
        }
        else
        {
            cur = inter(cur, a[i]);
        }
        suf.push_back(cur);
    }
    reverse(suf.begin(), suf.end());
    for (int i = 0; i < n; i++)
    {
        rect cur;
        if (i != 0)
        {
            cur = pref[i - 1];
        }
        else
        {
            cur = suf[i + 1];
        }
        if (i != n - 1)
        {
            cur = inter(cur, suf[i + 1]);
        }
        if (cur.x1 <= cur.x2 && cur.y1 <= cur.y2)
        {
            cout << cur.x1 << ' ' << cur.y1 << '\n';
            return 0;
        }
    }
}