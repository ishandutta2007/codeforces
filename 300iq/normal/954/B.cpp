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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        int len = i + 1;
        for (int j = i + 1; j + len - 1 < n && j <= i + 1; j++)
        {
            if (s.substr(0, len) == s.substr(j, len))
            {
                ans = min(ans, n - len + 1);
            }
        }
    }
    cout << ans << '\n';
}