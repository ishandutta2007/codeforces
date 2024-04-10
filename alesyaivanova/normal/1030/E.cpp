#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300010;
int a[MAX_N];
int n;
int cnt1[MAX_N];
int cnt2[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        while (x > 0)
        {
            if (x & 1)
                a[i]++;
            x >>= 1;
        }
    }
    int sum = 0;
    sum += a[0];
    if (a[0] % 2 == 1)
        cnt1[0]++;
    else
        cnt2[0]++;
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
        cnt1[i] = cnt1[i - 1];
        cnt2[i] = cnt2[i - 1];
        if (sum % 2 == 1)
            cnt1[i]++;
        else
            cnt2[i]++;
    }
    long long ans = 0;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum % 2 == 1)
            ans += cnt1[i] - 1;
        else
            ans += cnt2[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        int ma = 0;
        for (int e = i; e < min(i + 62, n); e++)
        {
            sum += a[e];
            ma = max(ma, a[e]);
            if (sum % 2 == 0 && sum < 2 * ma)
                ans--;
        }
    }
    cout << ans;
}