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
        vector<int> a;
        int n;
        cin >> n;
        a.resize(n);
        for (int &e : a) cin >> e;
        bool ok = 0;
        for (int i = 1; i < n; i++) if (a[i] >= a[i - 1]) ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}