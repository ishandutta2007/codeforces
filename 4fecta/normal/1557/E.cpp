// Problem: E. Assiut Chess
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

bool ask(int i, int j) {
    cout << i << " " << j << endl;
    string ret;
    cin >> ret;
    return ret == "Done";
}

void solve() {
    for (int i = 1; i <= 8; i++) {
        if (i & 1) {for (int j = 1; j <= 8; j++) if (ask(i, j)) return;}
        else for (int j = 8; j > 0; j--) if (ask(i, j)) return;
    }
    for (int i = 1; i <= 8; i++) {
        if (i & 1) {for (int j = 1; j <= 8; j++) if (ask(i, j)) return;}
        else for (int j = 8; j > 0; j--) if (ask(i, j)) return;
    }
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}