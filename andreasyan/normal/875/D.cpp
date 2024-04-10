#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int t[31];

int br[N], bl[N];
int ll[N], rr[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        bl[i] = 0;
        for (int j = 0; j < 31; ++j)
        {
            if (t[j] && !(a[i] & (1 << j)))
                bl[i] = max(bl[i], t[j]);
        }
        for (int j = 0; j < 31; ++j)
        {
            if ((a[i] & (1 << j)))
                t[j] = i;
        }
    }
    memset(t, 0, sizeof t);
    for (int i = n; i >= 1; --i)
    {
        br[i] = n + 1;
        for (int j = 0; j < 31; ++j)
        {
            if (t[j] && !(a[i] & (1 << j)))
            {
                br[i] = min(br[i], t[j]);
            }
        }
        for (int j = 0; j < 31; ++j)
        {
            if ((a[i] & (1 << j)))
                t[j] = i;
        }
    }
    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        if (s.empty())
            ll[i] = 0;
        else
            ll[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            rr[i] = n + 1;
        else
            rr[i] = s.top();
        s.push(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll[i]++;
        rr[i]--;
        if (ll[i] <= bl[i] && br[i] <= rr[i])
        {
            ans += (bl[i] - ll[i] + 1) * 1LL * (rr[i] - i + 1);
            ans += (i - ll[i] + 1) * 1LL * (rr[i] - br[i] + 1);
            ans -= (bl[i] - ll[i] + 1) * 1LL * (rr[i] - br[i] + 1);
        }
        else if (ll[i] <= bl[i])
        {
            ans += (bl[i] - ll[i] + 1) * 1LL * (rr[i] - i + 1);
        }
        else if (br[i] <= rr[i])
        {
            ans += (i - ll[i] + 1) * 1LL * (rr[i] - br[i] + 1);
        }
    }
    cout << ans << endl;
    return 0;
}