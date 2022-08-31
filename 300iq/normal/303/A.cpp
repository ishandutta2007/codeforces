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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << (i + i) % n << ' ';
    }
    cout << '\n';
}