#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m, k;
string s;
vector<int> pos[4];
string calc(int x, int y) {
    string ans;
    for(int i = 0; i < s.size(); i++) {
        if(i == x) continue;
        if(i == y) continue;
        if(s[i] == '0' && ans.size() == 0) continue;
        ans += s[i];
    }
    return ans;
}
void upd(string &ans, string cur) {
    if(ans.size() < cur.size()) ans=cur;
}
void solve() {
    cin >> s;
    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        sum = (sum + s[i] - '0') % 3;
        pos[(s[i] - '0') % 3].push_back(i);
    }
    if(sum == 0) {
        cout << s << "\n";
        return;
    }
    string ans;
    for(int i = 0; i < pos[sum].size() && i < 2; i++) {
        upd(ans, calc(pos[sum][i], -1));
    }
    for(int i = 1; i<pos[3-sum].size() && i < 3; i++) {
        upd(ans, calc(pos[3-sum][i], pos[3-sum][i-1]));
    }
    for(int i = 0; i < pos[0].size() && i < 1; i++) {
        string t = "";
        t += s[pos[0][i]];
        upd(ans, t);
    }
    if(ans.size() == 0) ans = "-1";

    cout << ans << "\n";
}


int main() {
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