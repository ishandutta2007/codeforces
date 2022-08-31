#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    int x;
    vector <int> f;
    for (int i = 0; i < n; i++) {
        cin >> x;
        f.push_back(x);
        ans += x;
    }
    sort(f.begin(), f.end());
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (f[i] > 0 && f[i + 1] > 0 && f[i] == f[i + 1]) {
                f[i]--; 
                flag = true;
            }
        }
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] > 0)
            ans += f[i];
    }
    cout << ans << endl;
}