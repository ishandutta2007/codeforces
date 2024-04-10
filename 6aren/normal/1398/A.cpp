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
        for (int &e : a) cin >> e;
        int mx = a.back();
        int u = a[0];
        int v = a[1];
        if (mx >= u + v) cout << 1 << ' ' << 2 << ' ' << n << endl;
        else cout << -1 << endl;
    }
    return 0;
}