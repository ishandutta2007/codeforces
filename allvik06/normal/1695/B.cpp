#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i1 = 0, i2 = 1;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
            if (i % 2 == 0 && x < a[i1]) i1 = i;
            if (i % 2 == 1 && x < a[i2]) i2 = i;
        }
        if (n % 2 == 1 || make_pair(a[i1], i1) > make_pair(a[i2], i2)) cout << "Mike\n";
        else cout << "Joe\n";
    }
}