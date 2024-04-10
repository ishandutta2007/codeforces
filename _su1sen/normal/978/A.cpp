#include<bits/stdc++.h>

using namespace std;

constexpr int M = 2000;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> r(M, n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r[a[i]] = i;
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (r[a[i]] == i) b.push_back(a[i]);
    }
    cout << b.size() << '\n';
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << " \n"[i == b.size() - 1];
    }
    return 0;
}