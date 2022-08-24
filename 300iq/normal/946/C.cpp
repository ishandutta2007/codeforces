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

int last[27];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    string s;
    cin >> s;
    char cur = 'a';
    for (auto &c : s)
    {
        if (c <= cur)
        {
            c = cur;
            cur++;
        }
        if (cur == 'z' + 1) break;
    }
    if (cur != 'z' + 1)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << s << '\n';
}