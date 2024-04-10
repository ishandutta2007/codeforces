#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    string ans1, ans2;
    if (b == 1) {
        if (k == 0) {
            ans1 += "1";
            ans2 += "1";
            for (int i = 0; i < a; ++i) {
                ans1 += "0";
                ans2 += "0";
            }
        } else {
            cout << "No";
            return 0;
        }
    } else if (a == 0) {
        if (k == 0) {
            for (int i = 0; i < b; ++i) {
                ans1 += "1";
                ans2 += "1";
            }
        } else {
            cout << "No";
            return 0;
        }
    } else {
        if (k > a + b - 2) {
            cout << "No";
            return 0;
        }
        if (k == 0) {
            cout << "Yes\n";
            for (int i = 0; i < b; ++i) cout << "1";
            for (int i = 0; i < a; ++i) cout << "0";
            cout << "\n";
            for (int i = 0; i < b; ++i) cout << "1";
            for (int i = 0; i < a; ++i) cout << "0";
            return 0;
        }
        ans1 += "1";
        ans2 += "1";
        b--;
        int kol0 = min(k, a);
        for (int i = 0; i < a - kol0; ++i) {
            ans1 += "0";
            ans2 += "0";
        }
        int kol1 = k + 1 - kol0;
        for (int i = 0; i < b - kol1; ++i) {
            ans1 += "1";
            ans2 += "1";
        }
        for (int i = 0; i < kol1; ++i) ans1 += "1";
        ans2 += "0";
        for (int i = 0; i < kol1 - 1; ++i) ans2 += "1";
        for (int i = 0; i < kol0; ++i) ans1 += "0";
        for (int i = 0; i < kol0 - 1; ++i) ans2 += "0";
        ans2 += "1";
    }
    cout << "Yes\n" << ans1 << "\n" << ans2;
    return 0;
}