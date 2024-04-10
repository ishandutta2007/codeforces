#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)200200;
const ll inf = (1ll<<50);

int n;
string s;
int p[maxn];
void solve() {
    cin >> n >> s;
    vector < int > sb[2];
    int sz = 0;
    for(int i = 0; i < n; i++) {
        int cur = s[i] - '0';
        if(sb[1-cur].size() == 0) {
            sz++;
            sb[1-cur].push_back(sz);
        }
        p[i] = sb[1-cur].back();
        sb[1-cur].pop_back();
        sb[cur].push_back(p[i]);
    }
    cout << sz << "\n";
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}