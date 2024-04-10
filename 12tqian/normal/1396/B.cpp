#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test_cases; cin >> test_cases;
    while (test_cases--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int sum = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) sum += a[i];
        if (2 * a.back() > sum || sum % 2 == 1) cout << "T\n";
        else cout << "HL\n";
    }
    return 0;
}