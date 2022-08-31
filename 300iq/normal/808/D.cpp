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
#include <iomanip>

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s += a[i];
    }
    if (s % 2)
    {
        puts("NO");
        return 0;
    }
    set <ll> q;
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        if (cur == s / 2)
        {
            puts("YES");
            return 0;
        }
        q.insert(a[i]);
        if (q.count(cur - s / 2))
        {
            puts("YES");
            return 0;
        }
    }
    reverse(a.begin(), a.end());
    q.clear();
    cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        if (cur == s / 2)
        {
            puts("YES");
            return 0;
        }
        q.insert(a[i]);
        if (q.count(cur - s / 2))
        {
            puts("YES");
            return 0;
        }
    }    
    puts("NO");
}