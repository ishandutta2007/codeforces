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
    set <char> x = {'a', 'e', 'i', 'o', 'u'};
    set <char> y = {'0', '2', '4', '6', '8'};
    string s;
    cin >> s;
    int ans = 0;
    for (auto c : s)
    {
        if (x.count(c) || ('0' <= c && c <= '9' && !y.count(c))) ans++;
    }
    cout << ans << '\n';
}