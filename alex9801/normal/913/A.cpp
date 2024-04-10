#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
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

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long n, m;
    scanf("%lld%lld", &n, &m);
    if(n > 40)
        printf("%lld", m);
    else
        printf("%lld", m % (1LL << n));
    return 0;
}