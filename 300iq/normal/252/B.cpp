#include <bits/stdc++.h>

using namespace std;

bool check(vector <int> a) {
    bool s1 = true;
    bool s2 = true;
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) s1 = false;
        if (a[i] > a[i + 1]) s2 = false;
    }
    return (s1 || s2);
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> ind;
    set <int> num;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            swap(a[i], a[i + 1]);
            if (!check(a)) {
                cout << i + 1  << " " << i + 2 << endl;
                return 0;
            }
            swap(a[i], a[i + 1]);
        }
    }
    cout << -1 << endl;
    return 0;
}