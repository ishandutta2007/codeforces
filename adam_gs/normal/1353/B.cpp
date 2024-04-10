#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n], b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a+n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b, b+n);
        for (int i = 0; i < k; ++i) {
            a[i]=max(a[i], b[n-i-1]);
        }
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s+=a[i];
        }
        cout << s << '\n';
    }
}