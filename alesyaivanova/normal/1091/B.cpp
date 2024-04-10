#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 1009;
pair<int, int> a[MAX_N];
pair<int, int> b[MAX_N];
int u = 4 * 1000 * 1000;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n; i++)
        cin >> b[i].first >> b[i].second;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
        {
            int x = a[i].first + b[e].first;
            int y = a[i].second + b[e].second;
            int k = (x + u) * 2 * u + (y + u);
            m[k]++;
        }
    }
    for (auto k : m)
    {
        if (k.second == n)
        {
            cout << k.first / (2 * u) - u << " " << k.first % (2 * u) - u;
            return 0;
        }
    }
}