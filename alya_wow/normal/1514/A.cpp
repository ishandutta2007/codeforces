#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool did = 0;
        for (int x : a) {
            bool f = 0;
            for (int j = 2; j * j <= x; j++)
            if (x % j == 0) {
                int z = 0;
                while (x % j == 0)
                    x /= j, z++;
                if (z % 2 == 1)
                    f = 1;
            }
            if (x != 1 || f) {
                did = 1;
                cout << "YES\n";
                break;
            }
        }
        if (!did)
            cout << "NO\n";
    }
}