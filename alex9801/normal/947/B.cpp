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

int arr[100010];
int tmp[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n; i++)
        scanf("%d", &tmp[i]);

    priority_queue<long long> pq;
    long long t = 0;
    for(i = 0; i < n; i++)
    {
        pq.push(-(arr[i] + t));

        long long c = 0;
        while(!pq.empty() && -pq.top() - t <= tmp[i])
        {
            c += -pq.top() - t;
            pq.pop();
        }

        t += tmp[i];
        c += 1LL * pq.size() * tmp[i];
        printf("%lld ", c);
    }
    
    return 0;
}