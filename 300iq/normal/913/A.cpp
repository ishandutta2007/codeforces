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
    int m, n;
    cin >> n >> m;
    if (n >= 60)
    {
        cout << m << '\n';
        return 0;
    }
    else
    {
        ll res = 1;
        for (int i = 0; i < n; i++) res *= 2;
        cout << m % res << '\n';
    }
}