#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e6 + 123;
const int mod = 1e9 + 7;
int n, k;
string s, t;

void solve() {
    cin >> n >> s >> t;

    if(s[0] == '0' && t[0] == '1') {
        for(int i = 0; i < n; i++) {
            cout << 1;
        }
        cout << "\n";
        return;
    }
    if(s == t || t[n-1] == '1') {
        cout << t << "\n";
        return;
    }
    int pos = n - 1;
    while(s[pos] == '1' && t[pos] == '0') pos--;
    if(s[pos] != '0' || t[pos] != '1') {
        t[n - 1] = '1';
    } else {
        pos--;
        while(pos >= 0 && t[pos] == s[pos]) pos--;
        if(pos >= 0) t[n - 1] = '1';
    }
    cout << t << "\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}