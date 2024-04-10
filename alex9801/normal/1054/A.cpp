#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int x, y, z, t1, t2, t3;
    scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);

    int c1 = abs(x - y) * t1;
    int c2 = abs(x - z) * t2 + 2 * t3 + abs(x - y) * t2 + t3;

    if(c2 <= c1)
        puts("YES");
    else
        puts("NO");

    return 0;
}