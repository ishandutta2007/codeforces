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
    int n;
    cin >> n;
    vector <int> a(n);
    vector <pair <int, int> > e;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        e.push_back({a[i], i});
    }
    vector <bool> win(n);
    sort(e.rbegin(), e.rend());
    for (auto c : e)
    {
        int i = c.second;
        int x = c.first;
        for (int j = i + x; j < n; j += x)
        {
            if (a[j] > a[i] && !win[j])
            {
                win[i] = true;
            }
        }
        for (int j = i - x; j >= 0; j -= x)
        {
            if (a[j] > a[i] && !win[j])
            {
                win[i] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (win[i]) cout << 'A';
        else cout << 'B';
    }
    cout << '\n';
}