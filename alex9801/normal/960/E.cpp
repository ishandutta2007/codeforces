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

int val[200010];
vector<int> arr[200010];
int cnt[200010][2];

int n;
int res;
const int mod = 1000000007;

void f(int x)
{
    cnt[x][0] = 1;
    for(int &y : arr[x])
    {
        arr[y].erase(find(arr[y].begin(), arr[y].end(), x));
        f(y);
        cnt[x][0] += cnt[y][1];
        cnt[x][1] += cnt[y][0];
    }
}

void g(int x, int c0, int c1)
{
    long long mul = 1LL * (c0 - c1) * (n - (c0 + c1)) % mod;

    int s0 = c1, s1 = c0 + 1;
    for(int &y : arr[x])
    {
        s0 += cnt[y][0];
        s1 += cnt[y][1];

        mul = (mul + 1LL * (cnt[y][1] - cnt[y][0]) * (n - (cnt[y][1] + cnt[y][0]))) % mod;
    }
    
    mul += n;

    res = ((res + 1LL * val[x] * mul) % mod + mod) % mod;

    for(int &y : arr[x])
        g(y, s0 - cnt[y][0], s1 - cnt[y][1]);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for(i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    f(1);
    g(1, 0, 0);

    printf("%d\n", res);
    return 0;
}