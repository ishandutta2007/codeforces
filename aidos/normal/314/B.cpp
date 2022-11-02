#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define filename ""
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int b, d;
string s, t;
pii dp[maxn];
pii dp2[maxn];
void solve() {
    cin >> b >> d >> s >> t;
    for(int i = 0; i < t.size(); i++) {
        int ok = 0;
        for(int j = 0; j < s.size(); j++) {
            if(t[i] == s[j]) {
                ok = 1;
            }
        }
        if(!ok) {
            cout << 0 << "\n";
            return;
        }
    }
    for(int j = 0; j < s.size(); j++) {
        int pos = j;
        int cnt = 0;
        for(int i = 0; i < t.size(); i++) {
            while(s[pos] != t[i]) {
                if(pos == 0) cnt++;
                pos = (pos + 1) % s.size();
            }
            if(pos == 0) cnt++;
            pos = (pos + 1) % s.size();
        }
        dp[j] = make_pair(pos, cnt);
    }
    for(int i = s.size()-1; i>=0; i--) {
        if(dp[i].second == 0) {
            pii nxt = dp2[dp[i].first];
            dp2[i] = make_pair(nxt.first, nxt.second + 1);
        } else {
            dp2[i] = make_pair(i, 0);
        }
    }
    int pos = 0;
    int ans = 0;
    int cc = 0;
    while(true) {
        if(cc + dp[pos].second > b) break;
        cc += dp[pos].second;
        pos = dp[pos].first;
        ans++;
        pii nxt = dp2[pos];
        ans += nxt.second;
        pos = nxt.first;
    }
    cout << ans/d << "\n";
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