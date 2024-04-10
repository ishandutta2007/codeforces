#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
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

    long long n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);

    long long t = 2LL * n * m;
    if(t % k != 0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");

    t /= k;

    long long x = (t + m - 1) / m;
    puts("0 0");
    printf("%lld %lld\n", x, x * m - t);
    printf("%lld %lld\n", 1LL, m);

    return 0;
}