#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> raz(n);
    set <int> h;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h.insert(a[i] % k);
    }
    map <int, int> m;
    int ind = 0;
    for (auto &c : h) {
        m[c] = ind;
        ind++;
    }
    vector < vector <int> > b(h.size(), vector <int> (10));
    for (int i = 0; i < n; i++) {
        int r = 0;
        int now = a[i];
        while (now > 0) {
            r++;
            now /= 10;
        }
        b[m[a[i] % k]][r - 1]++;
        raz[i] = r - 1;
    }
    vector < vector <int> > d(n, vector <int> (10));
    for (int i = 0; i < n; i++) {
        long long now = a[i];
        for (int j = 0; j < 10; j++) {
            now *= 10;
            now %= k;
            d[i][j] = now;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (h.find((k - d[i][j]) % k) == h.end()) {
                continue;
            }
            ans += b[m[(k - d[i][j]) % k]][j];
            if (raz[i] == j && a[i] % k == (k - d[i][j]) % k) {
                ans--;
            }
        }
    }
    cout << ans;
    return 0;
}