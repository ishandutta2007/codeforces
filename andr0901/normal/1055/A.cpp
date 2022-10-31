#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, s;
    cin >> n >> s;
    s--;
    vector <int> a(n), b(n);
    forn (i, 0, n)
        cin >> a[i];
    forn (i, 0, n)
        cin >> b[i];
    if (a[0] == 0) {
        cout << "NO";
        return 0;
    }
    if (a[s] == 1) {
        cout << "YES";
        return 0;
    }
    int f = 1;
    for (int i = s; i < n; i++) {
        if (a[i] == 1 && b[i] == 1) {
            f = 0;
            break;
        }
    }
    if (f == 1) {
        cout << "NO";
        return 0;
    }
    if (b[s] == 1) {
        cout << "YES";
        return 0;
    } else {
        cout << "NO";
        return 0;
    }
    cout << "NO";
    return 0;
}