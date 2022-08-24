
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
    cin >> n;
    if (n == 1)
    {
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    else
    {
        cout << 2 * (n - 1) << ' ' << 2 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
}