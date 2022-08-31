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
    vector <int> p(n);
    vector <bool> leaf(n, true);
    vector <int> cnt(n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
        leaf[p[i]] = false;
    }
    for (int i = 1; i < n; i++)
    {
        if (leaf[i]) cnt[p[i]]++;
    }
    for (int i = 0; i < n; i++) if (!leaf[i] && cnt[i] < 3)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
}