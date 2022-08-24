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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector <int> l(n), r(n);
        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
        }
        int cur_time = 0;
        for (int i = 0; i < n; i++)
        {
            if (cur_time > r[i])
            {
                cout << 0 << ' ';
                continue;
            }
            cur_time = max(cur_time, l[i]);
            cout << cur_time << ' ';
            cur_time++;
        }
        cout << '\n';
    }
}