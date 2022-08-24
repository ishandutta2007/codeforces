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
    string s;
    cin >> s;
    for (int sum = 0; sum <= 9 * n; sum++)
    {
        int it = 0;
        int cur = 0;
        for (auto c : s)
        {
            cur += c - '0';
            if (cur == sum)
            {
                it++;
                cur = 0;
            }
        }
        if (cur == 0 && it > 1)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}