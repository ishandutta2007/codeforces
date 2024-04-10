#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    if (n == 3) {
        cout << "1 1 1";
        return 0;
    }
    if (n % 3 == 0) {
        if ((n / 3) % 3 != 0)
            cout << n / 3 << " " << n / 3 << " " << n / 3;
        else
            cout << n / 3 - 2 << " " << n / 3 - 2 << " " << n / 3 + 4;
        return 0;
    }
    cout << n % 3 << " ";
    n -= n % 3;
    int k = n % 2;
    n /= 2;
    if (n % 3 == 0 && k) {
        cout << n - 1 << " " << n + 2;
    } else if (n % 3 == 0 && !k) {
        cout << n - 1 << " " << n + 1;
    } else if (n % 3 && !k) {
        cout << n << " " << n;
    } else {
        if (n % 3 == 1) {
            cout << n << " " << n + 1;
        } else {
            cout << n - 2 << " " << n + 3;
        }
    }
    return 0;
}