#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(all(a));
    int sum = 0;
    for (int e : a) sum += e;
    if (a.back() > sum / 2) cout << 'T' << endl;
    else {
        if (sum % 2 == 0) cout << "HL" << endl;
        else cout << "T" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}