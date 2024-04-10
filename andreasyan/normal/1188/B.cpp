#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct ban
{
    long long x;
};

long long n, M, k;
long long a[N];

map<long long, int> mp;

int main()
{
    scanf("%d%d%d", &n, &M, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        long long x = a[i] * a[i] % M * a[i] % M * a[i] % M - k * a[i] % M + M;
        x %= M;
        ans += mp[x];
        mp[x]++;
    }
    cout << ans << endl;
    return 0;
}