
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
*/

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
    vector <int> a(n), ans(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    vector <pair <int, int> > b;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        b.push_back({a[i] + a[j], i});
    }
    sort(b.rbegin(), b.rend());
    int sz = n - 1;
    for (auto c : b)
    {
        int ind = c.second;
        ans[ind] = sz--;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    puts("");
}