#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int pref[8005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<bool> check(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> pref[i];
            pref[i] += pref[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i - 1; j++) {
                if (pref[i] - pref[j] <= n) check[pref[i] - pref[j]] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int u = pref[i] - pref[i - 1];
            if (check[u]) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}