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
    scanf("%d", &n);
    map <int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    bool ok = false;
    for (auto c : cnt) if (c.second % 2) ok = true;
    cout << (ok ? "Conan" : "Agasa") << '\n';
}