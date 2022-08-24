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
    int n, m, k;
    cin >> n >> m >> k;
    vector <string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ans = 0;
    if (k <= m)
    {
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < k; j++)
            {
                cnt += (s[i][j] == '*');
            }
            for (int j = 0; j + k - 1 < m; j++)
            {
                if (cnt == 0) ans++;
                cnt -= (s[i][j] == '*');
                if (j + k < m) cnt += (s[i][j + k] == '*');
            }
        }
    }
    if (k <= n && k != 1)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            for (int i = 0; i < k; i++)
            {
                cnt += (s[i][j] == '*');
            }
            for (int i = 0; i + k - 1 < n; i++)
            {
                if (cnt == 0) ans++;
                cnt -= (s[i][j] == '*');
                if (i + k < n) cnt += (s[i + k][j] == '*');
            }
        }
    }
    cout << ans << '\n';
}