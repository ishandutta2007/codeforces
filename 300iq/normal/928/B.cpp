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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> ans(n);
    vector <int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        l[i] = max(0, i - k);
        r[i] = min(i + k, n - 1);
        if (a[i] != -1)
        {
            ans[i] = ans[a[i]] + (r[i] - l[i] + 1) - max(0, (min(r[i], r[a[i]]) - max(l[i], l[a[i]]) + 1));
        }
        else
        {
            ans[i] = r[i] - l[i] + 1;
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
}