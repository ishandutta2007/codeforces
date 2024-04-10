#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int a[MAXN][MAXN];

int cnt[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == 3) {
                cnt[i]++;
                cnt[j]++;
            }
            if (a[i][j] == 1) {
                cnt[i]++;
            }
            if (a[i][j] == 2) {
                cnt[j]++;
            }
        }
    }
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }
}