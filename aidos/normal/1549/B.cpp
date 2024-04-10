#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s, t;
int cost(int mask, int x, int y, int a, int b) {
    if(mask&1) {
        if(a == 0) return -maxn;
        //mask ^= 1;
        a = 0;
    }
    if(mask & 2) {
        if(b == 0) return -maxn;
        //mask ^= 2;
        b = 0;
    }
    int ans = 0;
    if(a > 0 && x > 0 && b > 0 && y > 0) ans+=2;
    else if(a > 0 && y > 0) {
        ans++;
    } else if(b > 0 && x > 0) {
        ans++;
    } else if(a == 0 && b > 0 && (mask & 1) == 0) {
        ans++;
    }
    return ans;

}
void solve(){
    cin >> n >> s >> t;
    vector<int> dp(4, -maxn);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        vector<int> d(4, -maxn);
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int mask = 0; mask < 4; mask++) {
                    d[mask] = max(d[mask], dp[j + k * 2] + cost(mask, j, k, s[i]-'0', t[i]-'0'));
                }
            }
        }
        dp = d;
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}