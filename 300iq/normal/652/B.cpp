#include <bits/stdc++.h>

using namespace std;

vector <int> a;
multiset <int> f;

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        f.insert(x);
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a.push_back(*f.begin());
            f.erase(f.begin());
        } else {
            a.push_back(*--f.end());
            f.erase(--f.end());
        }
    }
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] > a[i - 1]) {
                cout << "Impossible" << endl;
                return 0;
            }
        } else {
            if (a[i] < a[i - 1]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}