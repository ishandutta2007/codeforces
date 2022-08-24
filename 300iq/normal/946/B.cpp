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
    ll a, b;
    cin >> a >> b;
    while (a && b)
    {
        if (a >= 2 * b)
        {
            a %= 2 * b;
            continue;
        }
        if (b >= 2 * a)
        {
            b %= 2 * a;
            continue;
        }
        else
        {
            break;
        }
    }
    cout << a << ' ' << b << '\n';
}