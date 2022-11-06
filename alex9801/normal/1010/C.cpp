#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

int arr[100010];

int gcd(int x, int y)
{
    return x ? gcd(y % x, x) : y;
}

bool chk[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, i;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int g = k;
    for(i = 0; i < n; i++)
        g = gcd(g, arr[i] % k);

    int x = 0;
    while(1)
    {
        if(chk[x])
            break;
        chk[x] = 1;
        x = (x + g) % k;
    }

    vector<int> res;
    for(i = 0; i < k; i++)
        if(chk[i])
            res.push_back(i);

    printf("%d\n", (int)res.size());
    for(int t : res)
        printf("%d ", t);
    return 0;
}