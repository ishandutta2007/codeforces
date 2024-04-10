#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
long long x;
long long a[N];
long long p[N];

long long pp[N], ss[N];

long long ans;
void bandt(int l, int r)
{
    if (l == r)
    {
        ans = max(ans, p[l - 1] - pp[l - 1] + a[l] + ss[r] - p[r]);
        ans = max(ans, p[l - 1] - pp[l - 1] + a[l] * x + ss[r] - p[r]);
        return;
    }
    int m = (l + r) / 2;
    long long rr = 0;
    long long maxu = ss[r];
    for (int i = r; i >= m + 1; --i)
    {
        maxu = max(maxu, p[i]);
        rr = max(rr, (p[i] - p[m]) * x + maxu - p[i]);
    }
    rr = max(rr, maxu - p[m]);

    long long ll = 0;
    long long minu = pp[l - 1];
    for (int i = l; i <= m; ++i)
    {
        ll = max(ll, (p[m] - p[i - 1]) * x + p[i - 1] - minu);
        minu = min(minu, p[i]);
    }
    ll = max(ll, p[m] - minu);
    ans = max(ans, ll + rr);

    bandt(l, m);
    bandt(m + 1, r);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        pp[i] = min(pp[i - 1], p[i]);
    ss[n] = p[n];
    for (int i = n - 1; i >= 0; --i)
        ss[i] = max(ss[i + 1], p[i]);
    bandt(1, n);
    cout << ans << endl;
    return 0;
}