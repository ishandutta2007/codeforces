#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e4 + 7;

int a[100005], n;

int main()
{
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (long long)a[i] * (long long)a[n - i - 1];
        ans %= mod;
    }
    cout << ans << endl;
	return 0;
}