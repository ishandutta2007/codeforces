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

long long arr[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int q, i;
    scanf("%d", &q);
    for(int b = 0; b < q; b++)
    {
        int t;
        long long x, k;
        scanf("%d%lld", &t, &x);
        if(t == 1)
        {
            scanf("%lld", &k);
            for(i = 0;; i++)
            {
                long long s = 1LL << i;
                if(s <= x && x < 2 * s)
                {
                    arr[i] = ((arr[i] + k) % s + s) % s;
                    break;
                }
            }
        }
        else if(t == 2)
        {
            scanf("%lld", &k);
            for(i = 0; i < 60; i++)
            {
                long long s = 1LL << i;
                if(x < 2 * s)
                {
                    k = (k%s + s) % s;
                    arr[i] = ((arr[i] + k) % s + s) % s;
                    k *= 2;
                }
            }
        }
        else
        {
            for(i = 0; i < 60; i++)
            {
                long long s = 1LL << i;
                if(x < 2 * s)
                {
                    x += arr[i];
                    if(x < s)
                        x += s;
                    else if(x >= 2 * s)
                        x -= s;
                    break;
                }
            }

            vector<long long> res;
            while(x)
            {
                res.push_back(x);
                x /= 2;
            }

            int n = (int)res.size();
            for(i = n - 1; i >= 0; i--)
            {
                long long s = 1LL << i;
                long long t = res[n - i - 1] - arr[i];

                if(t < s)
                    t += s;
                else if(t >= 2 * s)
                    t -= s;
                printf("%lld ", t);
            }
            printf("\n");
        }
    }
    return 0;
}