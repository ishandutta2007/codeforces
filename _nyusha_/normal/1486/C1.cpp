#include<bits/stdc++.h>

using namespace std;

map < pair < int, int >, int > ask;

int get(int l, int r) {
    if (ask.find({l, r}) != ask.end()) {
        return ask[{l, r}];
    }
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    ask[{l, r}] = x;
    return x;
}

void solve(int l, int r) {
    if (l == r) {
        cout << "! " << l << endl;
        exit(0);
    }
    int m = (r + l) / 2;
    int pos = get(l, r);
    if (r - l == 1) {
        if (pos == l) solve(r, r);
        solve(l, l);
    }
    if (pos <= m) {
        if (get(l, m) == pos) solve(l, m);
        else solve(m + 1, r);
    }
    if (m + 1 == r) m--;
    if (get(m + 1, r) == pos) solve(m + 1, r);
    solve(l, m);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    solve(1, n);
    return 0;
}