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

struct triple
{
    int first, second, third;
};

bool operator < (const triple &a, const triple &b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <triple> e;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        e.push_back({l, r, i});
    }
    sort(e.begin(), e.end());
    int mx = -1e9;
    int pos = -1;
    for (auto c : e)
    {
        if (c.second > mx)
        {
            mx = c.second;
            pos = c.third;
        }
        else
        {
            cout << c.third + 1 << ' ' << pos + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
}