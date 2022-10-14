#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n *= 2;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> lol, kek;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) lol.pb(i + 1);
            else kek.pb(i + 1);
        }
        if (lol.size() % 2 == 1) {
            lol.pop_back();
            kek.pop_back();
        } else {
            if (lol.size()) {
                lol.pop_back();
                lol.pop_back();
            } else {
                kek.pop_back();
                kek.pop_back();
            }
        }
        for (int i = 0; i < lol.size(); i += 2) cout << lol[i] << " " << lol[i + 1] << "\n";
        for (int i = 0; i < kek.size(); i += 2) cout << kek[i] << " " << kek[i + 1] << "\n";
    }
    return 0;
}