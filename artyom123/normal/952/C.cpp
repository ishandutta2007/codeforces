#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector <int> a(n);
    for ( int i = 0; i < n; i++) {
            cin >> a[i];
    }
    while (a.size() > 1) {
        bool flag = false;
        for ( int i = 0; i + 1 < a.size(); i++) {
            if (abs(a[i] - a[i + 1] >= 2)) {
                cout << "NO";
                return 0;
            }
        }
        int max_now = a[0];
        for ( int i = 0; i < a.size(); i++) {
            max_now = max(max_now, a[i]);
        }

        int now;
        for ( int i = 0; i < a.size(); i++) {
            if ( a[i] == max_now) {
                now = i;
                break;
            }
        }

        a.erase(a.begin() + now);
    }
    cout << "YES";
    return 0;
}