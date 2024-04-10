#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int dp[555][555];
int a[555];
int D[555];
int n;
int get(int l, int r) {
    if(l == r) {
        return a[l];
    }
    int &res = dp[l][r];
    if(res) return res;
    res = -1;
    for(int i = l; i < r; i++) {
        int cl = get(l, i);
        int cr = get(i+1, r);
        if(cl != -1 && cl == cr) {
            return res = cl+1;
        }
    }
    return res;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) {
        D[i] = mod;
        for(int j = 0; j < i; j++) {
            if(get(j+1, i) != -1) {
                D[i] = min(D[i], D[j] + 1);
            }
        }
    }
    cout << D[n] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}