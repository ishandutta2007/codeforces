#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int T = 400;

int n;
char s[N];
int a[N];
int p[N];

long long ans;

int mp[T * N + N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf(" %s", s);
    n = strlen(s);
    for (int i = 1; i <= n; ++i)
        a[i] = s[i - 1] - '0';
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int k = 1; k < T; ++k)
    {
        for (int i = 0; i <= n; ++i)
        {
            ans += mp[i - k * p[i] + k * n];
            mp[i - k * p[i] + k * n]++;
        }
        for (int i = 0; i <= n; ++i)
            mp[i - k * p[i] + k * n]--;
    }
    vector<int> v;
    v.push_back(n + 1);
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == 1)
            v.push_back(i);
        for (int q = 1; ; ++q)
        {
            if ((int)v.size() - q - 1 < 0)
                break;
            int l = v[v.size() - q];
            int r = v[v.size() - q - 1] - 1;
            int s = max(i + ((l - i + 1) / q + !!((l - i + 1) % q)) * q - 1, i + T * q - 1);
            if (s > n)
                break;
            if (s > r)
                continue;
            ans += (1 + (r - s) / q);
        }
    }
    printf("%lld\n", ans);
    return 0;
}