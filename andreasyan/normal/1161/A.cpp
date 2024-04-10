#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
int f[N], s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        f[i] = s[i] = N;
    for (int i = 1; i <= k; ++i)
    {
        int x;
        cin >> x;
        if (f[x] == N)
            f[x] = i;
        s[x] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i] == N)
            ++ans;
        if (i != 1 && (s[i - 1] == N || s[i - 1] < f[i]))
            ++ans;
        if (i != n && (s[i + 1] == N || s[i + 1] < f[i]))
            ++ans;
    }
    cout << ans << endl;
    return 0;
}