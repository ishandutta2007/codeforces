#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        cout << b + x << ' ';
        x = max(x, b + x);
    }
    return 0;
}