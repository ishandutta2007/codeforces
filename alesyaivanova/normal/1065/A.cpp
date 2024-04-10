#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, a, b, c;
        cin >> s >> a >> b >> c;
        long long ans = s / c;
        ans += (ans / a) * b;
        cout << ans << "\n";
    }
}