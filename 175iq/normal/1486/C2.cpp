#include <bits/stdc++.h>
using namespace std;
 
int ask(int l, int r) {
    if (l >= r) return -1;
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}
 
int main() {
    int n;
    cin >> n;
    int smax = ask(0, n - 1);
    if (smax == 0 || ask(0, smax) != smax) {
        int l = smax, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ask(smax, m) == smax) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << "! " << r + 1 << endl;
    } else {
        int l = 0, r = smax;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ask(m, smax) == smax) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << "! " << l + 1 << endl;
    }
    return 0;
}