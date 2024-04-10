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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cur = 0;
    vector <int> lens;
    for (int i = 0; i < (int) s.size(); i++)
    {
        if (s[i] == '.')
        {
            cur++;
        }
        else
        {
            if (cur != 0) lens.push_back(cur);
            cur = 0;
        }
    }
    if (cur != 0) lens.push_back(cur);
    int ans = 0;
    for (int i = 0; i < (int) lens.size(); i++)
    {
        int x = lens[i] / 2;
        int y = lens[i] / 2 + lens[i] % 2;
        if (a > b) swap(a, b);
        ans += min(a, x);
        a -= min(a, x);
        ans += min(b, y);
        b -= min(b, y);
    }
    cout << ans << '\n';
}