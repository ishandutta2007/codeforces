#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n;
void solve() {
    cin >> n;
    if(n <= 30) {
        cout << "NO\n";
        return;
    }
    set<int> s = {6, 10, 14, n - 30};
    if(s.size() == 4) {
        cout << "YES\n6 10 14 " << n - 30 << "\n";
        return;
    }
    s = {6, 10, 15, n - 31};
    if(s.size() == 4) {
        cout << "YES\n6 10 15 " << n - 31 << "\n";
        return;
    }
    assert(false);
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