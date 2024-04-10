#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string T1[n];
    string T2[m];
    for (int i = 0; i < n; ++i) {
        cin >> T1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> T2[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        --a;
        cout << T1[a%n] << T2[a%m] << '\n';
    }
}