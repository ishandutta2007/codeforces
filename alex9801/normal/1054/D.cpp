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

int arr[200010];
int sum[200010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, i;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    for(i = 1; i <= n; i++)
        sum[i] = sum[i - 1] ^ arr[i];

    vector<int> v;

    int t = 1 << k;
    for(i = 0; i <= n; i++)
        v.push_back(min(sum[i], t - sum[i] - 1));

    sort(v.begin(), v.end());

    long long res = 0;

    int sz = v.size();
    int p = 0;
    for(i = 0; i < sz; i++)
    {
        if(i == sz - 1 || v[i] != v[i + 1])
        {
            int c = i - p + 1;
            int c0 = c / 2;
            int c1 = (c + 1) / 2;

            res += 1LL * c0 * (c0 - 1) / 2;
            res += 1LL * c1 * (c1 - 1) / 2;

            p = i + 1;
        }
    }

    res = 1LL * sz * (sz - 1) / 2 - res;

    printf("%lld\n", res);
    return 0;
}