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

const int N = 1e6 + 7;

int a[N];
ll suf[N];
int down_lim[N];
int up_lim[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int chet = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        chet ^= (a[i] % 2);
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }
    ll left = 0;
    for (int k = 1; k <= n + 1; k++)
    {
        ll right = k * (ll) (k - 1);
        int l = k - 1, r = n + 1;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (a[m] >= k)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        right += (l - k + 1) * (ll) k + suf[l + 1];
        ll value = max(-1ll, right - left);
        value = min(value, (ll) n);
        down_lim[k] = (int) value;
        left += a[k];
    }
    down_lim[n + 2] = n;
    for (int k = n + 1; k >= 1; k--)
    {
        down_lim[k] = min(down_lim[k], down_lim[k + 1]);
    }
    left = 0;
    for (int k = 1; k <= n; k++)
    {
        left += a[k];
        ll right = k * (ll) (k - 1);
        int l = k, r = n + 1;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (a[m] >= k)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        right += (l - k) * (ll) k + suf[l + 1];
        //left <= right + value
        //value + right >= left
        //value >= left - right
        ll value = left - right;
        value = max(value, 0ll);
        value = min(value, (ll) n + 1);
        up_lim[k] = value;
    }
    for (int k = 1; k <= n; k++)
    {
        up_lim[k] = max(up_lim[k], up_lim[k - 1]);
    }
    a[0] = n;
    a[n + 1] = -1;
    vector <int> ans;
    for (int k = 1; k <= n + 1; k++)
    {
        int l = a[k] + 1;
        int r = a[k - 1];
        l = max(l, up_lim[k - 1]);
        r = min(r, down_lim[k]);
        for (int i = l; i <= r; i++) if (i % 2 == chet) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) cout << -1;
    else for (int x : ans) cout << x << ' ';
    cout << '\n';
}