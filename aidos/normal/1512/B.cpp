#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int k;
string s[555];
void solve() {
    cin >> k;
    set<int> x, y;
    for(int i = 0; i < k; i++) {
        cin >> s[i];
        for(int j = 0; j < k; j++) {
            if(s[i][j] == '*') {
                x.insert(i);
                y.insert(j);
            }
        }
    }
    for(int i = 0; i < k; i++) {
        if(x.size() < 2) x.insert(i);
        if(y.size() < 2) y.insert(i);
    }
    for(int a: x) {
        for(int b: y) {
            s[a][b] = '*';
        }
    }
    for(int i = 0; i < k; i++) {
        cout << s[i] << "\n";
    }
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}