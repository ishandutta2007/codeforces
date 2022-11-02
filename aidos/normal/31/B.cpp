#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
int dp[maxn];
int prv[maxn];
string s;
void solve() {
    cin >> s;
    dp[0] = 1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '@') continue;
        int w = 0;
        for(int j = i; j >= 0; j--) {
            if(s[j] == '@') {
                if(w) break;
                w = 1;
            } else {
                if(w) {
                    if(dp[j]) {
                        prv[i + 1] = j;
                        dp[i + 1] = 1;
                    }
                }
            }
        }
    }
    if(dp[s.size()] == 0) {
        cout << "No solution\n";
        return;
    }
    string ans = "";
    int pos = s.size();
    while(pos > 0) {
        if(ans.size() > 0) ans = "," + ans;
        ans = s.substr(prv[pos], pos-prv[pos]) + ans;
        pos = prv[pos];
    }
    cout << ans << "\n";
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