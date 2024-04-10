#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<string>;

const int kBase = 97, kMod = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    Matrix a(n), b(m);
    for (auto x : {&a, &b}) {
        for (int i = 0; i < static_cast<int>(x->size()); ++i) {
            cin >> (*x)[i];
        }
    }

    unordered_map<int, int> sa;
    for (int i = 0; i + m - 1 < n; ++i) {
        int code = 0;
        for (int k = 0; k < m; ++k) {
            for (int j = 0; j < m; ++j) {
                code = ((long long)code * kBase + a[i + k][j] - 'a' + 1) % kMod;
            }
        }
        sa[code] = i;
    }

    for (int i = 0; i + m - 1 < n; ++i) {
        int code = 0;
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                code = ((long long)code * kBase + b[j][i + k] - 'a' + 1) % kMod;
            }
        }

        if (sa.find(code) != sa.end()) {
            cout << 1 + sa[code] << ' ' << 1 + i << endl;
            return 0;
        }
    }

}