#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)


void solve() {
    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    vector<int> ans;

    int sign = 1;
    int cur = 0;


    for (int i = n; i >= 1; i--) {
        int id = (i - cur) * sign;
        if ((a[id] == b[i]) == (sign == 1)) continue;
        int id1 = (1 - cur) * sign;
        if ((a[id1] == b[i]) == (sign == 1)) ans.pb(1);
        ans.pb(i);
        sign = -sign;
        cur = (1 + i) - cur;
    }

    cout << ans.size() << ' ';
    for (int e : ans) cout << e << ' ';
    cout << '\n';
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