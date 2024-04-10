#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int maxx = 1e5 + 1;

void solve1() {
    int n;
    cin >> n;
    vector <int> kol(maxx);
    int kol2 = 0, kol4 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++kol[x];
        if (kol[x] == 4) {
            kol2--;
            kol4++;
        }
        else if (kol[x] % 2 == 0) {
            ++kol2;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        char c;
        cin >> c >> x;
        if (c == '+') {
            ++kol[x];
            if (kol[x] == 4) {
                kol2--;
                kol4++;
            }
            else if (kol[x] % 2 == 0) {
                ++kol2;
            }
        }
        else {
            kol[x]--;
            if (kol[x] == 3) {
                kol4--;
                kol2++;
            }
            else if (kol[x] % 2 == 1) kol2--;
        }
        if (kol4 > 0 && (kol2 >= 2 || kol4 > 1)) cout << "YES\n";
        else cout << "NO\n";
    }
}

template <typename T> T solve2() {

}

signed main() {
    srand(time(nullptr));
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        solve1();
    }
    else {
        int t;
        cin >> t;
        while (t--) {

        }
    }
}