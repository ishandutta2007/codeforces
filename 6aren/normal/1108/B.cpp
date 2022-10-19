#include <bits/stdc++.h>

using namespace std;

int n, a[200], cnt[10005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
    cout << a[n] << " ";
    for (int i = n - 1; i >= 1; i--) {
        if (a[n] % a[i] != 0 || cnt[a[i]] > 1) {
            cout << a[i];
            break;
        }
    }
    //cin >> n;
    return 0;
}