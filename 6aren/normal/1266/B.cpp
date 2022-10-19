#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

bool check[50];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vi v;
    for (int i = 1; i <= 6; i++) {
        v.pb(21 - i);
    }
    int t;
    cin >> t;
    while (t--) {
        long long u;
        cin >> u;
        bool flag = 0;
        for (auto o : v) {
            if (u < o) continue;
            if ((u - o) % 14 == 0) flag = 1;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}