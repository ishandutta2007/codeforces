#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    string a;
    cin >> a;
    int num[2] = {};
    num[a[0] - '0']++;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            num[a[i] - '0']++;
    }
    if (!num[0])
    {
        cout << 0;
        return 0;
    }
    long long ans1 = num[0] * 1ll * y;
    long long ans2 = (num[0] - 1) * 1ll * x + y;
    cout << min(ans1, ans2);
}