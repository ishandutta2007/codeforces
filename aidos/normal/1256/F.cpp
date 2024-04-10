#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
string s, t;
string sorted(string str) {
    sort(str.begin(), str.end());
    return str;
}
void solve() {
    cin >> n >> s >> t;
    string ss = sorted(s);
    string tt = sorted(t);
    if(ss != tt) {
        cout << "NO\n";
        return;
    }
    for(int i = 1; i < n; i++) {
        if(ss[i] == ss[i-1]) {
            cout << "YES\n";
            return;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] > s[j]) {
                swap(s[i], s[j]);
                swap(t[0], t[1]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(t[i] > t[j]) {
                swap(t[i], t[j]);
                swap(s[0], s[1]);
            }
        }
    }
    if(s != t) {
        cout << "NO\n";
        return;
    }
    cout <<"YES\n";
}
int main() {
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}