#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long k, d, t;
    scanf("%lld%lld%lld", &k, &d, &t);
    t *= 2;
    if(d < k)
        d = ((k + d - 1) / d) * d;

    long long p = 2 * k + (d - k);
    long long r = 1.0 * (t / p) * d;
    t %= p;
    if(t <= 2 * k)
        printf("%.15lf", r + t / 2.0);
    else
        printf("%lld", r + k + (t - 2 * k));

    return 0;
}