
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
    int k;
    scanf("%d", &k);
    vector <int> a(k);
    int mx = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    printf("%d\n", max(0, mx - 25));
}