#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
vector<int> pref;
int n;
string s;
int d[maxn][2];
int dp[222][222][222][2];
int get(int pos, int bal, int sp, int eq){
    if(sp == s.size()) {
        sp = pref[sp-1];
        eq = 1;
    }
    if(bal<0) return 0;
    if(pos == n) {
        if(bal > 0) return 0;
        if(eq == 0) return 0;
        return 1;
    }
    int &res = dp[pos][bal][sp][eq];
    if(res != -1) return res;
    res = (get(pos + 1, bal - 1, d[sp][1], eq) + get(pos + 1, bal + 1, d[sp][0], eq)) % mod;
    return res;
}
void solve() {
    cin >> n;
    n *= 2;
    cin >> s;
    pref.resize(s.size(), 0);
    for(int i = 1; i < s.size(); i++) {
        int j = pref[i-1];
        while(j > 0 && s[i] != s[j]) j = pref[j-1];
        if(s[i]==s[j])++j;
        pref[i] = j;
    }
    for(int i = 0; i < s.size(); i++) {
        int j = i;
        while(j > 0 && s[j] != '(') j = pref[j-1];
        if(s[j] == '(') j++;
        d[i][0] = j;
        j = i;
        while(j > 0 && s[j] != ')') j = pref[j-1];
        if(s[j] == ')') j++;
        d[i][1] = j;
    }
    memset(dp, -1, sizeof dp);
    cout << get(0, 0, 0, 0) << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
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