#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

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
        int cnt0 = 0, cnt1 = 0, h = 0;
        int l = 0, r = n - 1;
        int pr = 0;
        for (int p = 0; l <= r; p++) {
            h = p + 1;
            if (p % 2 == 0) {
                int now = 0;
                while (l <= r && now <= pr) {
                    now += a[l];
                    l++;
                }
                cnt0 += now;
                pr = now;
            } else {
                int now = 0;
                while (l <= r && now <= pr) {
                    now += a[r];
                    r--;
                }
                cnt1 += now;
                pr = now;
            }
        }
        cout << h << " " << cnt0 << " " << cnt1 << "\n";
    }
    return 0;
}