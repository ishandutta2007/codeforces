#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n >= 3) {
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                for (int l = j + 1; l < n; ++l) {
                    int b = a[i] | a[j] | a[l];
                    ans = max(ans, b);
                }
        cout << ans;
    }
    if (n == 1) 
        cout << a[0];
    if (n == 2) {
        int b = a[0]|a[1];
        cout << b;
    }
    return 0;
}