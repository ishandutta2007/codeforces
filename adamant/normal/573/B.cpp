#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(auto &it: a)
        cin >> it;
    int b[n];
    memset(b, 0, sizeof(b));
    b[0] = 1;
    for(int i = 1; i < n; i++)
        b[i] = min(a[i], b[i - 1] + 1);
    int c[n];
    c[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
        c[i] = min(a[i], c[i + 1] + 1);
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, min(b[i], c[i]));
    cout << ans << "\n";
	return 0;
}