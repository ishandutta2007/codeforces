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

int f(int a, int b, int x, int y)
{
    return a * y - b * x;
}

int s(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return abs(f(x2 - x1, y2 - y1, x3 - x1, y3 - y1));
}

int s(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    return s(x1, y1, x2, y2, x3, y3) + s(x1, y1, x3, y3, x4, y4);
}

bool in(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int ans = s(x1, y1, x2, y2, x3, y3, x4, y4);
    ans -= s(x, y, x1, y1, x2, y2);
    ans -= s(x, y, x2, y2, x3, y3);
    ans -= s(x, y, x3, y3, x4, y4);
    ans -= s(x, y, x1, y1, x4, y4);
    return (ans == 0);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (in(x, y, 0, d, d, 0, n, n - d, n - d, n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}