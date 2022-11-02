#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int) 2e5 + 10;
int n;
int a[maxn];
string s;
void solve() {
    cin >> s;
    string t;
    for(char c: s) {
        if(c == 'B' && t.size() > 0 && t.back() == 'A') {
            t.pop_back();
        } else {
            t += c;
        }
    }
    s = t;
    t = "";
    for(char c: s) {
        if(c == 'B' && t.size() > 0 && t.back() == 'B') {
            t.pop_back();
        } else {
            t += c;
        }
    }
    cout << t.size() << "\n";
}
int main(){
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}