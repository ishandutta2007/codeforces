#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6, INF = 1e9;
using ld = double;

int n, m, q, is[1000];
string s, t;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> q >> s >> t;
    for(int i = 0; i + m - 1 < n; i++) {
        is[i] = 1;
        for(int j = 0; j < m && is[i]; j++) is[i] &= (s[i + j] == t[j]);
    }
    for(int i = 1; i < n; i++) is[i] += is[i - 1];
    while(q--) {
        int l, r; cin >> l >> r; l--; r--;
        r -= m - 1;
        if(r < l) cout << 0 << '\n';
        else cout << is[r] - (l ? is[l - 1] : 0) << '\n';
    }
}