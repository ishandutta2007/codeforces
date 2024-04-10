#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500010;
long long a[MAX_N];
int n;
long long s[MAX_N];
long long s0[MAX_N];
long long mi[MAX_N];
long long rs[MAX_N];
long long rs0[MAX_N];
long long rmi[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << a[0];
        return 0;
    }
    if (a[0] >= 0)
        s[0] = a[0];
    else
        s0[0] = a[0];
    mi[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= 0)
        {
            s[i] = s[i - 1] + a[i];
            s0[i] = s0[i - 1];
        }
        else
        {
            s0[i] = s0[i - 1] + a[i];
            s[i] = s[i - 1];
        }

        mi[i] = min(mi[i - 1], a[i]);
    }
    if (a[n - 1] >= 0)
        rs[n - 1] = a[n - 1];
    else
        rs0[n - 1] = a[n - 1];
    rmi[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= 0)
        {
            rs[i] = rs[i + 1] + a[i];
            rs0[i] = rs0[i + 1];
        }
        else
        {
            rs0[i] = rs0[i + 1] + a[i];
            rs[i] = rs[i + 1];
        }
        rmi[i] = min(rmi[i + 1], a[i]);
    }
    long long ans;
    if (rmi[1] < 0)
        ans = a[0] - (rs0[1] - rs[1]);
    else
        ans = a[0] - (rmi[1] - (rs[1] - rmi[1]));
    if (mi[n - 2] < 0)
        ans = max(ans, a[n - 1] - (s0[n - 2] - s[n - 2]));
    else
        ans = max(ans, a[n - 1] - (mi[n - 2] - (s[n - 2] - mi[n - 2])));
    for (int i = 1; i < n - 1; i++)
    {
        long long cur;
        if (rmi[i + 1] < 0)
            cur = a[i] - (rs0[i + 1] - rs[i + 1]);
        else
            cur = a[i] - (rmi[i + 1] - (rs[i + 1] - rmi[i + 1]));
        if (mi[i - 1] < 0)
            cur -= (s0[i - 1] - s[i - 1]);
        else
            cur -= (mi[i - 1] - (s[i - 1] - mi[i - 1]));
        ans = max(ans, cur);
    }
    cout << ans;
}