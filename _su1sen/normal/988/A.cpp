#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(101, 0);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        c[a] = i;
    }
    int s = 0;
    for (int b : c) {
        s += b > 0;
    }
    if (s < k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int i = 0;
        while (k --> 0) {
            while (not c[i]) i++;
            cout << c[i] << " \n"[k == 0];
            i++;
        }
    }
    return 0;
}