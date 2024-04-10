#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pref(2, vector<int>(n, 0));
    for (int &e : a) {
        cin >> e;
        e--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            pref[j][i] = (a[i] == j) + (i == 0 ? 0 : pref[j][i - 1]);
        }
    }

    auto calc = [&](int id, int l, int r) {
        return pref[id][r] - (l == 0 ? 0 : pref[id][l - 1]);
    };

    vector<vector<int>> mx(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        mx[i][i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            mx[j][i] =  max(calc(0, j, i), mx[j + 1][i] + (a[j] == 1));
        }
    }

    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int tmpAns = mx[l][r];
            if (l > 0) tmpAns += calc(0, 0, l - 1);
            if (r != n - 1) tmpAns += calc(1, r + 1, n - 1);
            ans = max(ans, tmpAns);
        }
    }

    cout << ans << '\n';

    return 0;
}