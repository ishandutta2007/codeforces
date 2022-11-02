#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    int m;
    cin >> m;
    pair<int, int> b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i].first >> b[i].second;
    sort(a, a + n);
    sort(b, b + m);
    int j = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m && b[j].first < a[i].first)
        {
            ans += b[j].second;
            j++;
        }
        if (j < m && b[j].first == a[i].first)
        {
            ans += max(a[i].second, b[j].second);
            j++;
        }
        else
        {
            ans += a[i].second;
        }
    }
    while (j < m)
    {
        ans += b[j].second;
        j++;
    }
    cout << ans;
}