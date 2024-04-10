#include <bits/stdc++.h>

using namespace std;
const int MAXN = 500000;
int f[MAXN];

void update(int k, int x, int n)
{
    for (int i = k; i < n; i = i | (i + 1))
        f[i] += x;
}

int sum(int k)
{
    int ans = 0;
    for (int i = k; i >= 0; i = ((i & (i + 1)) - 1))
        ans += f[i];
    return ans;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int a[MAXN], b[MAXN], c[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
    {
        c[2 * i] = a[i];
        c[2 * i + 1] = b[i];
    }
    sort(c, c + 2 * n);
    int k = unique(c, c + 2 * n) - c;
    map<int, int> m;
    for (int i = 0; i < k; i++)
        m[c[i]] = i;
    int p[MAXN], q[MAXN];
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = m[a[i]];
        q[i] = m[b[i]];
    }
    int d[MAXN];
    for (int i = 0; i < k; i++)
        d[i] = i;
    for (int i = 0; i < n; i++)
        swap(d[p[i]], d[q[i]]);
    for (int i = k - 1; i >= 0; i--)
    {
        ans += (long long)sum(d[i]);
        ans += (long long)abs ((c[d[i]] - d[i]) - (c[i] - i));
        update(d[i], 1, k);
    }
    cout << ans;
    return 0;
}