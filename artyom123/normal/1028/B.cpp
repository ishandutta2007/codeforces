#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb emplace_back()
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> ans1(n);
    vector <int> ans2(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans1[n - i - 1] = 9;
            ans2[n - i - 1] = 1;
            continue;
        }
        if (i % 2 == 1) {
            ans1[n - i - 1] = 4;
            ans2[n - i - 1] = 5;
            continue;
        }
        ans1[n - i - 1] = 8;
        ans2[n - i - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans1[i];
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans2[i];
    }
    return 0;
}