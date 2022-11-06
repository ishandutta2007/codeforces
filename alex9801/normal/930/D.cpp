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

struct pos
{
    int x, y;
    bool operator <(const pos &a) const
    {
        return x != a.x ? x < a.x : y < a.y;
    }
};

int lmin[100010];
int lmax[100010];
int rmin[100010];
int rmax[100010];
const int INF = 10000000;

long long f(vector<pos> &arr)
{
    int n, i;
    n = arr.size();

    if(n < 4)
        return 0;

    for(i = 0; i <= n; i++)
    {
        lmin[i] = rmin[i] = INF;
        lmax[i] = rmax[i] = -INF;
    }

    sort(arr.begin(), arr.end());

    for(i = 1; i < n; i++)
    {
        pos &c = arr[i - 1];

        lmin[i] = min(lmin[i - 1], c.y);
        lmax[i] = max(lmax[i - 1], c.y);
    }

    for(i = n - 1; i >= 1; i--)
    {
        pos &c = arr[i];

        rmin[i] = min(rmin[i + 1], c.y);
        rmax[i] = max(rmax[i + 1], c.y);
    }

    long long res = 0;

    for(i = 1; i < n; i++)
    {
        int hi = min(lmax[i], rmax[i]);
        int lo = max(lmin[i], rmin[i]);

        if(hi <= lo)
            continue;

        res += 1LL * ((hi - lo) / 2) * ((arr[i].x - arr[i - 1].x) / 2);
    }

    return res;
}

vector<pos> arr1, arr2;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        if((x + y) % 2 == 0)
            arr1.push_back({ x + y, x - y });
        else
            arr2.push_back({ x + y, x - y });
    }

    long long res = f(arr1) + f(arr2);
    
    printf("%lld", res);
    return 0;
}