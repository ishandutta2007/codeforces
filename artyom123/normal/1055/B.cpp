#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, l;
    cin >> n >> m >> l;
    vector <long long> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > l && (i == n - 1 || a[i + 1] <= l)) {
            ans++;
        }
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << ans << "\n";
        }
        else {
            long long p, d;
            cin >> p >> d;
            if (a[p - 1] <= l && a[p - 1] + d <= l) {
                a[p - 1] += d;
                continue;
            }
            int now = 0;
            if (a[p - 1] <= l && a[p - 1] + d > l) {
                a[p - 1] += d;
                if (p - 2 >= 0 && a[p - 2] > l) {
                    now++;
                }
                if (p < n && a[p] > l) {
                    now++;
                }
                if (now == 0) {
                    ans++;
                }
                if (now == 2) {
                    ans--;
                }
            }
        }
    }
    return 0;
}