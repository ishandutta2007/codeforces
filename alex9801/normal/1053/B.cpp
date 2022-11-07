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

int arr[300010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);

        while(x)
        {
            arr[i] += x % 2;
            x /= 2;
        }
    }

    long long r = 0;

    int s = 0;
    int cnt[2] = { 1, 0 };
    for(i = 1; i <= n; i++)
    {
        if(arr[i] % 2)
            s = !s;

        r += cnt[s];
        cnt[s]++;
    }

    for(i = 1; i <= n; i++)
    {
        int s = arr[i];
        int cnt[2] = { 0, 0 };

        cnt[arr[i] % 2]++;

        int p = i - 1;
        while(p >= 1 && arr[p] < arr[i] && s + arr[p] < 2 * arr[i])
        {
            s += arr[p];
            cnt[s % 2]++;
            p--;
        }
        p++;

        r -= cnt[0];

        int q = i + 1;
        while(q <= n && arr[q] <= arr[i])
        {
            while(p < i && s + arr[q] >= 2 * arr[i])
            {
                cnt[s % 2]--;
                s -= arr[p];
                p++;
            }

            if(s + arr[q] >= 2 * arr[i])
                break;

            if(arr[q] % 2 == 1)
                swap(cnt[0], cnt[1]);

            s += arr[q];
            q++;

            r -= cnt[0];
        }
    }

    printf("%lld\n", r);
    return 0;
}