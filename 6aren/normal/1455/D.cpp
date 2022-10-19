#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

bool check(vector<int> a) {
    for (int i = 2; i < a.size(); i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ids;
    int cur = x;
    for (int i = 1; i <= n; i++) {
        if (a[i] > cur) {
            cur = a[i];
            ids.push_back(i);
        }
    }
    int ans = -1;
    for (int i = -1; i < (int) ids.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j <= i; j++) tmp.push_back(ids[j]);
        vector<int> b = a;
        for (int j = 0; j < tmp.size(); j++) {
            int u = tmp[j];
            if (j == 0) b[u] = x;
            else b[u] = a[tmp[j - 1]];
        }
        // for (int e : b) cout << e << ' ';
        // cout << endl;
        if (check(b)) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        solve();
    } 

    return 0;
}