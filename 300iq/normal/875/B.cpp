
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
    int last = n - 1;
    set <int> s;
    printf("%d ", 1);
    for (int i = 0; i < n; i++)
    {
        int p;
        scanf("%d", &p);
        p--;
        if (p <= last)
        {
            s.insert(p);
        }
        while (!s.empty() && *s.rbegin() == last)
        {
            s.erase(--s.end());
            last--;
        }
        printf("%d ", (int) s.size() + 1);
    }
    puts("");
}