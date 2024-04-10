#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 200000;
int cnt[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long double s;
    int n;
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt[a - 1]++;
        cnt[b - 1]++;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 1)
            k++;
    }
    cout.precision(20);
    cout << fixed << 2 * (s / k);
}