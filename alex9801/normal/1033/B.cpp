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
    
    int t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);

        if(a - b > 1)
            puts("NO");
        else
        {
            long long t = 2 * b + 1;

            bool ok = 1;
            for(long long j = 2; j * j <= t; j++)
            {
                if(t % j == 0)
                {
                    ok = 0;
                    break;
                }
            }

            if(ok)
                puts("YES");
            else
                puts("NO");
        }
    }

    return 0;
}