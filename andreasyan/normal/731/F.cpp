#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int p[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    for (int i = 1; i < N; ++i)
        p[i] = p[i - 1] + a[i];
    long long ans = 0;
    for (int i = 1; i < N; ++i)
    {
        if (!a[i])
            continue;
        long long yans = 0;
        for (int j = i; j < N; j += i)
        {
            int k = j + i - 1;
            k = min(k, N - 1);
            yans += (p[k] - p[j - 1]) * 1LL * j;
        }
        ans = max(ans, yans);
    }
    cout << ans << endl;
    return 0;
}