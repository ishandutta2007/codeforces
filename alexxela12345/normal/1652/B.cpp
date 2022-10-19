#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

//#define int ll
#ifndef LOCAL
//#define endl '\n'
#endif

#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    map<char, int> last;
    for (int i = 0; i < n; i++) {
        last[s[i]] = i;
    }
    int l = 0;
    while (last[s[l]] != l) {
        l++;
    }
    cout << s.substr(l, n - l) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}