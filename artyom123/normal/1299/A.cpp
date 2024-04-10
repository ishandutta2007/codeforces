#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> cnt(30);
    vector<int> a(n);
    for (auto &c : a) {
        cin >> c;
        for (int i = 0; i < 30; i++) {
            if (c & (1 << i)) {
                cnt[i]++;
            }
        }
    }
    int f = -1;
    int mx = -1;
    for (int i = 0; i < 30; i++) {
        if (cnt[i] == 1) {
            int now = 0;
            int pos = -1;
            for (int j = 0; j < n; j++) {
                if (a[j] & (1 << i)) {
                    pos = j;
                    for (int k = 0; k < 30; k++) {
                        if (cnt[k] == 1 && (a[j] & (1 << k))) {
                            now |= (1 << k);
                        }
                    }
                }
            }
            if (now > mx) {
                mx = now;
                f = pos;
            }
        }
    }
    if (f != -1) {
        cout << a[f] << " ";
    }
    for (int i = 0; i < n; i++) {
        if (i != f) {
            cout << a[i] << " ";
        }
    }
    return 0;
}