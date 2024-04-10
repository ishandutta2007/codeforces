#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    sum *= 2;
    for (int i = 0; i < n; i++) {
        if (sum / n >= 9) {
            cout << i;
            return 0;
        }
        sum += (5 - a[i]) * 2;
        if (sum / n >= 9) {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}