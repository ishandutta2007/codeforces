#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 3e5 + 100;
const int mod = (int)998244353 ;
int dp[555][555];
string s;
int n;
int get(int l, int r) {
    if(l > r) return 0;
    if(l == r) return 1;
    int &res = dp[l][r];
    if(res != 0) return res;
    res = get(l + 1, r) + 1;
    for(int i = l + 1; i <= r; i++) {
        if(s[i] == s[l]) res =  min(get(l+1, i-1) + get(i, r), res);
    }
    return res;
}
void solve() {
    cin >> n >> s;
    cout << get(0, n-1) << "\n";
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