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
    vector <int> a(n);
    int ans = -1e9;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= 0)
        {
            int p = 0;
            while (p * p < x) p++;
            if (p * p != x) ans = max(ans, x);
        }
        else
        {
            ans = max(ans, x);
        }
    }
    cout << ans << '\n';
}