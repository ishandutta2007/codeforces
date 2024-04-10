#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        sort(all(a));
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            int j = i, mx = a[i];
            while (j + 1 < n && mx > cnt + (j - i)) {
                j++;
                mx = a[j];
            }
            if (j == n - 1 && mx > cnt + (j - i)) break;
            cnt += j - i + 1;
            i = j;
        }
        cout << cnt << "\n";
    }
    return 0;
}