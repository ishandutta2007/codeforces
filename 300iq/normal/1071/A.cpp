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
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector <int> nums;
    for (ll i = 1; i * (i + 1) / 2 <= a + b; i++)
    {
        nums.push_back((int) i);
    }
    vector <int> l, r;
    for (int i = (int) nums.size() - 1; i >= 0; i--)
    {
        if (a >= nums[i])
        {
            a -= nums[i];
            l.push_back(nums[i]);
        }
        else
        {
            r.push_back(nums[i]);
        }
    }
    cout << l.size() << '\n';
    for (int x : l) cout << x << ' ';
    cout << '\n';
    cout << r.size() << '\n';
    for (int x : r) cout << x << ' ';
    cout << '\n';
}