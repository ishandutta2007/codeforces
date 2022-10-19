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
        int n, k;
        cin >> n >> k;
        if (n % 2 == k % 2 && n >= k) {
            cout << "YES" << "\n";
            for (int i = 1; i < k; i++) {
                cout << 1 << ' ';
            }
            cout << n - k + 1 << '\n';
        } else if (n % 2 == 0) {    
            if (n < 2 * k) {
                cout << "NO\n";
                continue;
            }  
            cout << "YES\n";
            for (int i = 1; i < k; i++) cout << 2 << ' ';
            cout << n - (k - 1) * 2 << '\n';
        } else cout << "NO\n";
    }
    return 0;
}