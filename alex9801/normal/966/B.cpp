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

pair<int, int> arr[300010];
int n;

bool solve(int x1, int x2, vector<int> &res1, vector<int> &res2)
{
    res1.clear();
    res2.clear();

    int i, j;
    int k2 = -1;
    for(i = n - 1; i >= 0; i--)
    {
        int t = (x2 + arr[i].first - 1) / arr[i].first;
        if(i + t > n)
            continue;

        k2 = i;
        for(j = i; j < i + t; j++)
            res2.push_back(arr[j].second);

        break;
    }

    for(i = 0; i < n; i++)
    {
        int t = (x1 + arr[i].first - 1) / arr[i].first;
        if(i + t > k2)
            continue;

        for(j = i; j < i + t; j++)
            res1.push_back(arr[j].second);

        return 1;
    }
    return 0;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int x1, x2, i;
    scanf("%d%d%d", &n, &x1, &x2);
    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        arr[i] = { x, i + 1 };
    }

    sort(arr, arr + n);

    vector<int> res1, res2;
    if(solve(x1, x2, res1, res2) || solve(x2, x1, res2, res1))
    {
        printf("Yes\n");
        printf("%d %d\n", (int)res1.size(), (int)res2.size());
        for(int t : res1)
            printf("%d ", t);
        printf("\n");
        for(int t : res2)
            printf("%d ", t);
        printf("\n");
    }
    else
        printf("No\n");

    return 0;
}