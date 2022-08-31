
/*
      
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
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
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    vector <pair <int, int> > b;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        b.push_back({x, i});
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    vector <int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[b[i].second] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    puts("");
}