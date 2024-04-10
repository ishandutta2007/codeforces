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
    int n, r;
    cin >> n >> r;
    vector <int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector <long double> y(n);
    for (int i = 0; i < n; i++)
    {
        long double cur = r;
        for (int j = 0; j < i; j++)
        {
            if (abs(x[i] - x[j]) <= 2 * r)
            {
                ll dist = 4 * r * r;
                dist -= (x[i] - x[j]) * (ll) (x[i] - x[j]);
                long double d = sqrt(dist);
                cur = max(cur, y[j] + d);
            }
        }
        y[i] = cur;
        cout << fixed << setprecision(20) << y[i] << ' ';
    }
    cout << '\n';
}