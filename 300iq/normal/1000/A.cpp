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
    map <string, int> s;
    for (int i = 0; i < n; i++)
    {
        string q;
        cin >> q;
        s[q]++;
    }
    for (int i = 0; i < n; i++)
    {
        string q;
        cin >> q;
        s[q]--;
    }
    int ans = 0;
    for (auto c : s)
    {
        ans += abs(c.second);
    }
    cout << ans / 2 << '\n';
}