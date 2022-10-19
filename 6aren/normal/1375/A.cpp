#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool sign = 1;
        if (a[0] > 0) sign = 0;
        for (int i = 1; i < n; i++) {
            if (sign) a[i] = abs(a[i]);
            else a[i] = -abs(a[i]);
            sign ^= 1;
        }
        for (int e : a) cout << e << ' ';
        cout << '\n';
    }
    return 0;
}