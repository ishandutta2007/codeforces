#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
string s;
int n;
ld dp[maxn];
ld d[maxn];
const string vowels = "IEAOUY";
bool vowel(char c) {
    for(const char &x: vowels) {
        if(x == c) return true;
    }
    return false;
}
void solve() {
    for(int i = 1; i < maxn; i++) {
        d[i] = d[i-1] + ld(1)/i;
    }
    for(int i = 1; i < maxn; i++) {
        dp[i] = dp[i-1] + d[i];
    }
    cin >> s;
    n = s.size();
    ld ans = 0;
    for(int i = 0; i < n; i++) {
        if(vowel(s[i])) {
            ans += dp[n] - dp[i] - dp[n - i - 1];
        }
    }
    printf("%.12lf\n", (double) ans);
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}