#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 0; i < m; ++i) {
        long long v;
        cin >> v;
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (a[mid] < v) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << r << ' ' << v - a[l] << '\n';
    }
    return 0;
}