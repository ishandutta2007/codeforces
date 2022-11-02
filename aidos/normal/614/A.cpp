#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
ll l, r, k;
void solve() {
    cin >> l >> r >> k;
    ll val = 1;
    vector <ll> ans;
    while(true) {
        if(val >= l) ans.emplace_back(val);
        if(r/k >= val && val * k <= r) {
            val *= k;
        } else {
            break;
        }
    }
    if(ans.size() == 0) {
        cout << -1 << "\n";
    } else {
        for(const ll &val: ans) cout << val << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}