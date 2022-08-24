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

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    int res = (int) 2e9 - n;
    if (n != (int) 1e9)
    {
        res = (int) 1e9 - n;
    }
    for (int d = 1; d < 10; d++)
    {
        int x = d;
        for (int len = 0; len < 9; len++)
        {
            if (x > n)
            {
                res = min(res, x - n);
            }
            x *= 10;
        }
    }
    cout << res << '\n';
}