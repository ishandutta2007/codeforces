#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a.size() < b.size();
}

bool check(string a, string b) {
    for (int i = 0; i + a.size() - 1 < b.size(); ++i) {
        string tmp = b.substr(i, a.size());
        if (tmp == a) {
            return true;
        }
    }
    return false;
}
signed main() {
    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (check(a[i], a[j])) {
                break;
            }
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }
}