#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a[100100];

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int x;
        cin >> s >> x;
        n = s.size();
        string ans = string(n, '1');
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                if(i >= x) {
                    ans[i-x] = '0';
                }
                if(i + x < n) {
                    ans[i + x] = '0';
                }
            }
        }
        int bad = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') continue;
            int ok = 0;
            if(i >= x) {
                ok |= (ans[i-x] == '1');
            }
            if(i+x<n) {
                ok |= (ans[i+x] == '1');
            }
            if(ok == 0) {
                bad = 1;
            }
        }
        if(bad) {
            ans = "-1";
        }
        cout << ans << "\n";
    }
}