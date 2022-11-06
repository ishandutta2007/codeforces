#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
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

    int t, s, a, b, c, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        scanf("%d%d%d%d", &s, &a, &b, &c);

        long long r = s / (1LL * a * c) * (a + b);
        s %= 1LL * a * c;
        r += s / c;
        printf("%lld\n", r);
    }

    return 0;
}