#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 == 0) cnt0++;
            else cnt1++;
        }
        if (cnt0 == 0 && x % 2 == 0) {
            cout << "No\n";
            continue;
        }
        if (cnt1 == 0) {
            cout << "No\n";
            continue;
        }
        if (x == n) {
            if (cnt1 % 2 == 0) {
                cout << "No\n";
                continue;
            }
        }
        cout << "Yes\n";
    }
    return 0;
}