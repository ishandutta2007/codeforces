#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool bad = false;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] + 1 != b[i]) bad = true;
        }
        if (bad) cout << "NO\n";
        else cout << "YES\n";
    }
}