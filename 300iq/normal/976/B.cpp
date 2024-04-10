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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll k;
    cin >> k;
    if (k < n)
    {
        cout << k + 1 << ' ' << 1 << '\n';
    }
    else
    {
        k -= n;
        k++;
        if (k < m)
        {
            cout << n << ' ' << k + 1 << '\n';
        }
        else
        {
            k -= m;
            int row = k / (m - 1);
            int col = k % (m - 1);
            cout << n - 1 - row << ' ' << (row % 2 == 1 ? col + 2 : m - col) << '\n';
        }
    }
}