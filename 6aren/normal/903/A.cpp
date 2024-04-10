#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        bool flag = 0;
        for (int i = 0; i <= 100; i++) {
            if (x - i * 3 >= 0 && (x - i * 3) % 7 == 0) flag = 1;
        }
        cout << ((flag) ? "YES\n" : "NO\n");
    }
    return 0;
}