
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e5 + 10;
int n, m, k;
void out(string ans, int len) {
    int cnt4 = 0, cnt7 = 0;
    for(char c: ans) {
        if(c == '4') cnt4++;
        else if(c == '7') cnt7++;
        else {
            assert(false);
        }
    }
    while(cnt4 + cnt7 != len) {
        if(cnt4 < len/2) {
            ans += '4';
            cnt4++;
        } else {
            ans += '7';
            cnt7++;
        }
    }
    cout << ans << "\n";
    exit(0);
}
void solve() {
    string s;
    cin >> s;
    if(s.size() % 2 == 1 || string(s.size()/2, '7') + string(s.size()/2,'4') < s) {
        int x = s.size() + 1;
        if(x % 2 == 1) x++;
        out("", x);
    }
    int cnt4=0, cnt7= 0;
    string ans;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] < '4') {
            out(ans, s.size());
        }
        if(s[i] == '4') {
            if(cnt4 == s.size()/2) {
                out(ans, s.size());
            }
            cnt4++;
            ans += '4';
            continue;
        }
        if(s[i] > '7' || (cnt7 == s.size()/2)) {
            if(cnt7 == s.size()/2) {
                while (ans.back() != '7') {
                    cnt4--;
                    ans.pop_back();
                }
            }
            while(ans.back() == '7') {
                cnt7--;
                ans.pop_back();
            }
            cnt4--;
            ans.pop_back();
            cnt7++;
            ans += '7';
            out(ans, s.size());
            return;
        }
        if(s[i] < '7') {
            ans += '7';
            out(ans, s.size());
        }
        ans += '7';
        cnt7++;
    }
    out(ans, s.size());
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}