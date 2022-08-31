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
#include <chrono>

using namespace std;

typedef long long ll;

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 1e9 + 7;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string t;
    cin >> t;
    vector <int> one(n), zer(n);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '1')
        {
            a++;
        }
        else
        {
            b++;
        }
        one[i] = a, zer[i] = b;
    }
    vector <int> s(n + 1);
    vector <int> me(n + 1);
    for (int i = 1; i <= n; i++)
    {
        me[i] = (1 + s[i - 1]) % M;
        s[i] = (s[i - 1] + me[i]) % M;
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int a = (one[r] - (l ? one[l - 1] : 0));
        int b = (zer[r] - (l ? zer[l - 1] : 0));
        cout << (s[a] + (s[b] * (ll) s[a]) % M) % M << '\n';
    }
}