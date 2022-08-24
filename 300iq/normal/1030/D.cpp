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
    ll n, m;
    cin >> n >> m;
    ll x = n, y = m;
    ll b;
    cin >> b;
    ll who = 0;
    ll g = __gcd(n, b);
    n /= g, b /= g;
    g = __gcd(m, b);
    m /= g, b /= g;
    if (b != 1 && b != 2)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        cout << "YES\n";
        if (b == 1)
        {
            if (n * 2 <= x)
            {
                cout << 0 << ' ' << 0 << '\n';
                cout << n * 2 << ' ' << 0 << '\n';
                cout << 0 << ' ' << m << '\n';
            }
            else
            {
                cout << 0 << ' ' << 0 << '\n';
                cout << 0 << ' ' << m * 2 << '\n';
                cout << n << ' ' << 0 << '\n';
            }
        }
        else
        {
            cout << 0 << ' ' << 0 << '\n';
            cout << 0 << ' ' << m << '\n';
            cout << n << ' ' << 0 << '\n';
        }
    }
}