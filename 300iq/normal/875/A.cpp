
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

int s(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    vector <int> ans;
    for (int cur = 1; cur <= min(5000, n); cur++)
    {
        if (n - cur + s(n - cur) == n)
        {
            ans.push_back(n - cur);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int) ans.size());
    for (int c : ans)
    {
        printf("%d ", c);
    }
    puts("");
}