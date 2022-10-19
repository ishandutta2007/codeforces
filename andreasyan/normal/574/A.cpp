#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    priority_queue<int> q;
    for (int i = 2; i <= n; ++i)
        q.push(a[i]);
    int ans = 0;
    while (q.top() >= a[1])
    {
        ++ans;
        int x = q.top();
        q.pop();
        ++a[1];
        --x;
        q.push(x);
    }
    printf("%d\n", ans);
    return 0;
}