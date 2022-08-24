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
    vector <int> s(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        s[i] = a + b + c + d;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] > s[0]) ans++;
    }
    cout << ans << '\n';
}