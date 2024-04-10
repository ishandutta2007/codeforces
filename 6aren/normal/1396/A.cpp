#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

int a[N], n;

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << ' ' << 1 << endl;
        cout << a[1] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << a[1] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << -3 * a[1] << endl;
        return 0;
    }
    cout << 1 << ' ' << n - 1 << endl;
    for (int i = 1; i <= n - 1; i++) {
        cout << (n - 1) * a[i] << ' ';
        a[i] += (n - 1) * a[i]; 
    }
    cout << endl;
    cout << 2 << ' ' << n << endl;
    for (int i = 2; i <= n - 1; i++) {
        cout << 0 << ' ';
    }
    cout << a[n] * (n - 1) << endl;
    a[n] *= n;
    cout << 1 << ' ' << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << -a[i] << ' ';
    }
    return 0;
}