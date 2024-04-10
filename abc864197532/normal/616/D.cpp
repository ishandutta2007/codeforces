#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n), cnt(1000001, 0);
    int cur = 0, ans = 1;
    int ll = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n) {
            if (cnt[a[j]] == 0) cur++;
            cnt[a[j]]++;
            j++;
            if (cur > k) {
                j--;
                cnt[a[j]]--;
                cur--;
                break;
            }
        }
        ans = max(ans, j - i);
        if (ans == j - i) ll = i;
        cnt[a[i]]--;
        if (cnt[a[i]] == 0) cur--;
    }
    cout << ll + 1 << ' ' << ll + ans << endl;
}