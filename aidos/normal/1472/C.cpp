#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)5e5 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
string s;
int n;
void solve(){
    cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int j = min(i + x, n);
        a[j] = max(a[j], a[i] + x);
    }
    cout << a[n] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}