#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 2e5 + 10;
const int mod = 998244353;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, m, k;
vector<int> calc(int sz) {
    vector<int> a(sz+1, 0);
    int last = 0;
    for(int i = 1; i <= sz; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            last = i;
        } else {
            a[i-last]++;
        }
    }
    for(int i = sz-1; i > 0; i--) {
        a[i] += a[i+1];
    }
    return a;
}
void solve() {
    cin >> n >> m >> k;
    vector<int> a = calc(n);
    vector<int> b = calc(m);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(k % i == 0 && k/i <= m) {
            ans += a[i] * b[k/i];
        }
    }
    cout << ans << "\n";
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