#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int a = arr[i - 1];
            int b = arr[i];
            if (b < a) 
                swap(a, b);
            while (a * 2 < b) {
                a *= 2;
                ans++;
            }
        }
        cout << ans << endl;
    }
}