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

    int x, d, i, j;
    scanf("%d%d", &x, &d);

    long long c = 1;
    long long p = 1;
    vector<long long> res;
    for(i = 0; x; i++)
    {
        if(x % 2)
        {
            for(j = 0; j < i; j++)
                res.push_back(c);
            c += d + 1;
            res.push_back(c);
            c += d + 1;
        }
        x /= 2;
    }

    printf("%d\n", (int)res.size());
    for(long long &t : res)
        printf("%lld ", t);
    printf("\n");
    return 0;
}