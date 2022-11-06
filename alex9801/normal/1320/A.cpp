#include <bits/stdc++.h>
using namespace std;

int arr[200010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    long long mx = 0;
    map<int, long long> m;
    for(int i = 1; i <= n; i++)
    {
        long long c = arr[i];

        auto it = m.find(i - arr[i]);
        if(it != m.end())
        {
            c = arr[i] + it->second;
            it->second = c;
        }
        else
            m[i - arr[i]] = c;

        mx = max(mx, c);
    }

    printf("%lld\n", mx);
    return 0;
}