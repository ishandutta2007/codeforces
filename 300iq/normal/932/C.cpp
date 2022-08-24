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
    int n, a, b;
    cin >> n >> a >> b;
    int sz = 0;
    for (int x = 0; x <= n; x++)
    {
        ll cur = x * (ll) a;
        if ((n - cur) % b == 0 && n - cur >= 0)
        {
            ll l = x;
            ll r = (n - cur) / b;
            for (int i = 0; i < l; i++)
            {
                int l = sz;
                for (int j = 0; j < a; j++)
                {
                    cout << l + (j + 1) % a + 1 << ' ';
                }
                sz += a;
            }
            for (int i = 0; i < r; i++)
            {
                int l = sz;
                for (int j = 0; j < b; j++)
                {
                    cout << l + (j + 1) % b + 1 << ' ';
                }
                sz += b;
            }
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}