#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n, m;
int a[maxn], b[maxn];
void solve() {

    cin >> n >> m;
    set<int> s;
    for(int i=0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++) {
        if(s.count(b[i])) {
            cout << "YES\n1 " << b[i] << "\n";
            return;
        }
    }
    cout << "NO\n";
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