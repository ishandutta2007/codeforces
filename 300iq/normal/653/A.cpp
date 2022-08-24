#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> t;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x, t.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (t[i] != t[j] && t[j] != t[k] && t[i] != t[k] && max(t[i], max(t[j], t[k])) - min(t[i], min(t[j], t[k])) <= 2) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}