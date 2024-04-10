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

    long long n, m, i;
    scanf("%lld%lld", &n, &m);

    long long mn = max(0LL, n - 2 * m);
    long long mx = 0;

    for(i = 0; i <= n; i++)
    {
        if(m <= i * (i - 1) / 2)
        {
            mx = n - i;
            break;
        }
    }

    printf("%lld %lld\n", mn, mx);
    return 0;
}