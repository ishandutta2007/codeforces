#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(5000);
    vector <int> b(5000);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x - y+1000]++;
        b[y +  x]++;
    }long long ans = 0;
    for (int i = 0; i < 5000; i++) {
        ans += (a[i] * (long long)(a[i] - 1)) / 2;
        ans += (b[i] * (long long)(b[i] - 1)) / 2;
    }
    cout << ans << endl;
}