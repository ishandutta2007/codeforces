#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, w, b;
int pos, l, r;
void solve() {
    cin >> n >> pos >> l >> r;
    if(l == 1 && r == n) {
        cout << 0 << "\n";
        return;
    }
    if(l == 1) {
        cout << abs(r - pos) + 1 << "\n";
        return;
    }
    if(r == n) {
        cout << abs(pos-l) + 1 << "\n";
        return;
    }
    cout << min(abs(pos - l) + r - l, abs(r - pos) + r - l) + 2 << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}