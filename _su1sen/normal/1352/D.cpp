#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int x = 0, y = 0;
        int c = 0;
        int l = 0, r = n - 1;
        int p = 0;
        while (l <= r) {
            int s = 0;
            while (s <= p and l <= r) {
                s += a[l++];
            }
            ++c;
            x += s;
            if (r < l) break;
            p = s;
            s = 0;
            while (s <= p and l <= r) {
                s += a[r--];
            }
            ++c;
            p = s;
            y += s;
        }
        cout << c << ' ' << x << ' ' << y << '\n';
    }
    return 0;
}