#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];
int p[N];

int q[1 << 22][2];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] ^ a[i];
    }
    long long ans = 0;
    q[p[0]][0]++;
    for (int i = 1; i <= n; ++i)
    {
        ans += q[p[i]][i % 2];
        q[p[i]][i % 2]++;
    }
    cout << ans << endl;
    return 0;
}