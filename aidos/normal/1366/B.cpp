#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, L, R;
void solve() {
    cin >> n >> L >> m;
    R = L;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if(L>r) continue;
        if(R < l) continue;
        R = max(R, r);
        L = min(L, l);
    }
    cout << R - L + 1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}