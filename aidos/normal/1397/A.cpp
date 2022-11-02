#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n, m;
int a[maxn], b[maxn];
void solve() {

    cin >> n;
    map<char, int> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(char c: s) {
            m[c]++;
        }
    }
    for(auto [c, d]: m) {

        if(d % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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