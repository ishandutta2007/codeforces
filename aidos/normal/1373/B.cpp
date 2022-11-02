#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n, m;
void solve() {
    cin >> s;
    int x = 0, y = 0;
    for(char c: s) {
        if(c == '0') x += 1;
        else y += 1;
    }
    if(min(x, y) % 2 == 1) {
        cout <<"DA\n";
    } else {
        cout << "NET\n";
    }
}

int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}