#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int n, m;
string s[25], t[25];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        y--;
        cout << s[y % n] + t[y % m] << '\n';
    }
    return 0;
}