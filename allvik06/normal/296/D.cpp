#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector <vector <int>> f(n, vector <int> (n, -1));
    vector <int> z(n), ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> z[i]; --z[i];
    }
    vector <bool> now(n);
    for (int i = 0; i < n; ++i) {
        f[i][i] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        now[z[i]] = true;
        for (int j = 0; j < n; ++j) {
            if (f[z[i]][j] == -1 || f[z[i]][j] > a[z[i]][j]) f[z[i]][j] = a[z[i]][j];
            if (f[j][z[i]] == -1 || f[j][z[i]] > a[j][z[i]]) f[j][z[i]] = a[j][z[i]];
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (f[j][z[i]] != -1 && f[z[i]][k] != -1 && (f[j][k] == -1 || f[j][k] > f[j][z[i]] + f[z[i]][k])) {
                    f[j][k] = f[j][z[i]] + f[z[i]][k];
                }
            }
        }
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (f[j][k] != -1 && now[j] && now[k]) sum += f[j][k];
            }
        }
        ans[i] = sum;
    }
    for (int i : ans) cout << i << " ";
}