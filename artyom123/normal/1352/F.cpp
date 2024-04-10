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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string ans = "";
        if (n1 == 0 && n2 > 0) {
            for (int j = 0; j <= n2; j++) ans += '1';
            cout << ans << "\n";
            continue;
        }
        int now = 0;
        for (int i = 0; i <= n1; i++) {
            if (now == 0 && n0 > 0) {
                for (int j = 0; j <= n0; j++) ans += '0';
                n0 = 0;
                now = 1;
                continue;
            }
            if (now == 0 && n0 == 0) {
                now = 1;
                ans += '0';
                continue;
            }
            if (now == 1 && n2 > 0) {
                for (int j = 0; j <= n2; j++) ans += '1';
                n2 = 0;
                now = 0;
                continue;
            }
            ans += '1';
            now = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}