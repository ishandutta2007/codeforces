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
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (b > 2 * a) cout << a << '\n';
        else cout << (a + b) / 3 << '\n';
    }
    return 0;
}