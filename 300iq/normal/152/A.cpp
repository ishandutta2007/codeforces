#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, ans;
    char tmp;
    ans = 0;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            a[i][j] = tmp - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        bool prev = false;
        for (int j = 0; j < m; ++j) {
            bool tec = true;
            for (int k = 0; k < n; ++k)
                if (a[k][j] > a[i][j])
                    tec = false;
            if (tec)
                prev = true;
        }
        if (prev)
            ans++;
    }
    cout << ans;
}