#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
string gen(int len, int s, int bad) {
    string ans = "";
    for(int i = 0; i < len; i++) {
        if(s == 0) {
            ans += "0";
        } else {
            int x = s - (len - i - 1) * 9;
            if(x <= 0) {
                if(i == 0 && !bad) {
                    ans += char('1');
                    s -= 1;
                } else {
                    ans += '0';
                }
            } else {
                s -= x;
                ans += char(x + '0');
            }
        }
    }
    return ans;
}
string calc(string last, int s) {
    if(s > last.size() * 9) {
        int len = (s + 8)/9;
        return gen(len, s, 0);
    }
    string ans = "", pref = "";
    int S = s;
    for(int i = 0; i < last.size(); i++) {
        for(char j = last[i] + 1; j <= '9'; j++) {
            int cur = S - (j - '0');
            string tmp = pref;
            tmp += j;
            if(cur > 9 * (last.size() - i - 1) || cur < 0) continue;
            tmp += gen(last.size() - i - 1, cur, 1);
            if(ans.size()  == 0) ans = tmp;
            else ans = min(ans, tmp);
        }
        pref += last[i];
        S -= (last[i] - '0');
    }
    if(ans.size() == 0) ans = gen(last.size() + 1, s, 0);
    return ans;
}
void solve() {
    cin >> n;
    string last = "";
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        last = calc(last, x);
        cout << last << "\n";
    }
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}