#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 4 || k <= n) {
        cout << -1 << endl;
        return 0;
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> used;
    for (int i = 1; i <= n; i++) {
        used.insert(i);
    }
    used.erase(a);
    used.erase(b);
    used.erase(c);
    used.erase(d);
    cout << a << " " << c << " ";
    for (int el : used) {
        cout << el << " ";
    }
    cout << d << " " << b << endl;
    cout << c << " " << a << " ";
    for (int el : used) {
        cout << el << " ";
    }
    cout << b << " " << d << endl;
}