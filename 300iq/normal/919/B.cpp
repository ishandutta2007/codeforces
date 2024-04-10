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

int k;

vector <int> ans;

void rec(int i, int sum, int cur, int len)
{
    if (len > 10) return;
    if (sum > 10) return;
    if (sum == 10 && len == 10)
    {
        ans.push_back(cur);
        if ((int) ans.size() == k)
        {
            cout << ans.back() << '\n';
            exit(0);
        }
    }
    else
    {
        for (int t = 0; t < 10; t++)
        {
            rec(i + 1, sum + t, cur * 10 + t, len + 1);
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    cin >> k;
    rec(0, 0, 0, 0);
}