#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 500009;
int a[MAX_N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] *= -1;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i] *= -1;
    int cnt_full = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != n)
            break;
        cnt_full++;
    }
    for (int i = cnt_full + 1; i <= n; i++)
    {
        a[i - cnt_full] = a[i] - cnt_full;
    }
    n -= cnt_full;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] < 0)
        {
            cout << -1;
            return 0;
        }
        if (a[i] == 0)
            n--;
    }
    if (n == 0)
    {
        cout << cnt_full;
        return 0;
    }
    int left = 0;
    int right = n;
    int u1 = 1;
    int u2 = 1;
    int j = n + 1;
    int pref = 0;
    int suf = 0;
    for (int k = 1; k <= n - 1; k++)
    {
        pref += a[k];
        while (j < k + 1)
        {
            suf -= a[j];
            j++;
        }
        while (j - 1 >= k + 1 && a[j - 1] <= k)
        {
            j--;
            suf += a[j];
        }
        int cur = k * (k - 1) + suf + k * (j - (k + 1));
        if (k == 1 || a[k] != a[k - 1])
        {
            u1 = k;
            u2 = k;
            while (u2 + 1 <= n && a[u2 + 1] == a[u1])
                u2++;
        }
        int cur_left = n;
        int cur_left1 = max(0ll, min(u1 - 1, pref - cur));
        if (pref - cur_left1 <= cur)
            cur_left = min(cur_left1, cur_left);
        pref -= u1 - 1;
        if (a[u2] <= k)
            cur -= u2 - k;
        cur_left1 = max(0ll, min(k - u1 + 1, pref - cur));
        if (pref - cur_left1 <= cur)
            cur_left = min(cur_left, cur_left1 + u1 - 1 + u2 - k);
        if (a[u2] <= k)
            cur += u2 - k;
        pref += u1 - 1;
        left = max(left, cur_left);

        int cur_right = 0;
        if (a[u2] <= k)
        {
            pref -= k;
            cur -= u2 - k;
            int cur_right1 = max(0ll, min(n - u2, cur - pref));
            if (pref <= cur - cur_right1)
                cur_right = max(cur_right, cur_right1 + u2);
            cur += u2 - k;
            pref += k;
        }
        else
        {
            pref -= k;
            int cur_right1 = max(0ll, min(n - j + 1, cur - pref));
            if (pref <= cur - cur_right1)
                cur_right = max(cur_right, cur_right1 + j - 1);
            pref += k;
        }
        if (pref - u1 + 1 <= cur)
            cur_right = max(cur_right, u1 - 1);
        if (a[u2] <= k)
        {
            int cur_right1 = max(0ll, min(u2 - k, cur - (pref - u1 + 1)));
            if (pref - u1 + 1 <= cur - cur_right1)
                cur_right = max(cur_right, u1 - 1 + cur_right1);
        }
        right = min(right, cur_right);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i];
    if ((sum + left) % 2 == 1)
        left++;
    if ((sum + right) % 2 == 1)
        right--;
    if (right < left)
        cout << -1;
    left += cnt_full;
    right += cnt_full;
    for (int i = left; i <= right; i += 2)
        cout << i << " ";
}