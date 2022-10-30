#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> numbers(n);
    for (int i = 0; i < n; i++) cin >> numbers[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] + numbers[n - i - 1] == 1) {
            cout << -1;
            return 0;
        }
        if (numbers[i] == 2 && numbers[n - i - 1] == 2) {
            ans += min(a, b);
        }
        else if (numbers[i] == 2 && numbers[n - i - 1] == 1) ans += b;
        else if (numbers[i] == 2 && numbers[n - i - 1] == 0) ans += a;
    }
    cout << ans;
    return 0;
}