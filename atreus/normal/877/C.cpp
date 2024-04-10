#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = n / 2 + n / 2 + n / 2;
    ans += n % 2;
    cout << ans << endl;
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
}