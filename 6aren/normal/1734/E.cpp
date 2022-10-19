#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) {
        cin >> e;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<  (a[i] + ((j - i) * i + n * n)) % n << ' '; 
        } 
        cout << '\n';
    }
    return 0;
}