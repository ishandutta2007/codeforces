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
    vector <int> deg(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        deg[a]++;
        deg[b]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1) ans++;
    }
    cout << ans << '\n';
}