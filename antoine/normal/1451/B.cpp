#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    map<char, int> firstOcc, lastOcc;
    for(int i = 0; i < n; ++i) {
        if(!firstOcc.count(s[i]))
            firstOcc[s[i]] = i;
        lastOcc[s[i]] = i;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << (firstOcc[s[l]] != l || lastOcc[s[r]] != r ? "YES" : "NO") << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       f();
    }
    return 0;
}