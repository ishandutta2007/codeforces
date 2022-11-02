#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 1e6 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int L[maxn], R[maxn];
int n;
int a[maxn];
int dp[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        L[i] = R[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        R[a[i]] = i;
        if(L[a[i]] == -1) L[a[i]] = i;
    }
    vector<int> b;
    for(int i = 1; i <= n; i++) {
        if(L[i]!=-1) b.push_back(i);
    }
    dp[0] = 1;
    for(int i = 1; i < b.size(); i++) {
        if(L[b[i]] > R[b[i-1]]) {
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = 1;
        }
    }
    cout << b.size() - *max_element(dp, dp + b.size()) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}