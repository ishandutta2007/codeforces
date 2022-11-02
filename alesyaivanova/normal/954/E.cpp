#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, te;
    cin >> n >> te;
    pair<long long, long long> t[n];
    for (int i = 0; i < n; i++)
        cin >> t[i].second;
    long long sum1 = 0;
    long long sum2 = 0;
    long long x1 = 0;
    long long x2 = 0;
    long long x3 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].first;
        t[i].first -= te;
        if (t[i].first > 0)
        {
            sum1 += t[i].first * t[i].second;
            x1 += t[i].second;
        }
        else if (t[i].first < 0)
        {
            sum2 += -t[i].first * t[i].second;
            x2 += t[i].second;
        }
        else
        {
            x3 += t[i].second;
        }
    }
    sort(t, t + n);
    if (sum1 == sum2)
    {
        cout << x1 + x2 + x3;
        return 0;
    }
    if (sum1 > sum2)
    {
        double ans = 0;
        int j = lower_bound(t, t + n, make_pair(1ll, 0ll)) - t;
        for (; j < n; j++)
        {
            if (t[j].first * t[j].second <= sum2)
            {
                sum2 -= t[j].first * t[j].second;
                ans += t[j].second;
            }
            else
            {
                ans += ((double) sum2) / t[j].first;
                sum2 = 0;
                break;
            }
        }
        cout.precision(20);
        ans += x2 + x3;
        cout << fixed << ans;
    }
    else
    {
        double ans = 0;
        int j = lower_bound(t, t + n, make_pair(0ll, 0ll)) - t;
        j--;
        for (; j >= 0; j--)
        {
            if (-t[j].first * t[j].second <= sum1)
            {
                sum1 += t[j].first * t[j].second;
                ans += t[j].second;
            }
            else
            {
                ans -= ((double) sum1) / t[j].first;
                sum1 = 0;
                break;
            }
        }
        cout.precision(20);
        ans += x1 + x3;
        cout << fixed << ans;
    }
}