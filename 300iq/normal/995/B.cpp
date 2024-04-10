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
    vector <int> a(2 * n);
    vector <int> l(n, -1), r(n - 1);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    for (int i = 0; i < 2 * n; i += 2)
    {
        int x = -1;
        for (int j = i; j < 2 * n; j++)
        {
            if (a[j] == a[i])
            {
                x = j;
            }
        }
        for (int j = x; j > i + 1; j--)
        {
            swap(a[j], a[j - 1]);
            ans++;
        }
    }
    cout << ans << '\n';
}