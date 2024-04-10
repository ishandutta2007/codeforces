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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int free = 0, zero = 0, one = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '1')
        {
            if (a[i] == '0') x++;
            else y++;
        }
        if (a[i] == '0')
        {
            zero++;
        }
        else
        {
            one++;
        }
    }
    cout << n * (ll) (n - 1) / 2 - (zero * (ll) (zero - 1) / 2 + one * (ll) (one - 1) / 2 + x * (ll) y) << '\n';
}