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
        if (n <= 3) {
            cout << -1 << "\n";
            continue;
        }
        int cur = 2;
        vector<int> p;
        while ((int)p.size() + 8 <= n) {
            p.pb(cur);
            p.pb(cur + 2);
            p.pb(cur - 1);
            p.pb(cur + 1);
            cur += 4;
        }
        if (n % 4 == 0) {
            p.pb(cur);
            p.pb(cur + 2);
            p.pb(cur - 1);
            p.pb(cur + 1);
        }
        if (n % 4 == 1) {
            p.pb(cur);
            p.pb(cur + 2);
            p.pb(cur - 1);
            p.pb(cur + 1);
            p.pb(cur + 3);
        }
        if (n % 4 == 2) {
            p.pb(cur);
            p.pb(cur + 4);
            p.pb(cur + 2);
            p.pb(cur - 1);
            p.pb(cur + 1);
            p.pb(cur + 3);
        }
        if (n % 4 == 3) {
            p.pb(cur);
            p.pb(cur + 4);
            p.pb(cur + 2);
            p.pb(cur + 5);
            p.pb(cur + 3);
            p.pb(cur - 1);
            p.pb(cur + 1);
        }
        for (auto &c : p) cout << c << " ";
        cout << "\n";
    }
    return 0;
}