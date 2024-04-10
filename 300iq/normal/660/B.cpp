#include <bits/stdc++.h>

using namespace std;

int left0, left1, right0, right1;
vector <int> l0, l1, r0, r1;

int main() {
    int n, m;
    cin >> n >> m;
    int cur = 1;
    for (int i = 1; i <= min(2 * n, m); i++) {
        if (i & 1) {
            left0++;
            l0.push_back(cur++);
        } else {
            right0++;
            r0.push_back(cur++);
        }
    }
    for (int i = 2 * n + 1; i <= m; i++) {
        if (i & 1) {
            left1++;
            l1.push_back(cur++);
        } else {
            right1++;
            r1.push_back(cur++);
        }
    }
    reverse(l0.begin(), l0.end());
    reverse(l1.begin(), l1.end());
    reverse(r0.begin(), r0.end());
    reverse(r1.begin(), r1.end());
    for (int i = 1; i <= m; i++) {
        if (left1 > 0) {
            cout << l1.back() << " ";
            l1.pop_back();
            left1--;
        }
        if (left0 > 0) {
            cout << l0.back() << " ";
            l0.pop_back();
            left0--;
        }
        if (right1 > 0) {
            cout << r1.back() << " ";
            r1.pop_back();
            right1--;
        }
        if (right0 > 0) {
            cout << r0.back() << " ";
            r0.pop_back();
            right0--;
        }
    }
}