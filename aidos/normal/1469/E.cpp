#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
int n, m;
string s;
int u[1<<22];
int u2[1<<22];
int T;
void solve() {
    cin >> n >> m >> s;
    int k = 20;
    T++;
    int st = max(0, m - k);
    string ans = "";
    for(int i = 0; i < st; i++) {
        ans += "0";
    }
    if(st > 0) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                j = max(i - st + 1, j);
                while(j <= i) {
                    u2[j] = T;
                    j++;
                }
            }
        }
    }
    for(int i = 0; i + m<= n; i++) {
        if(u2[i] == T) continue;
        int cur=0;
        for(int j = st; j < m; j++) {
            cur = cur * 2 + s[i + j] - '0';
        }
        u[cur] = T;
    }
    for(int mask = 0; mask < (1<<(m-st)); mask++) {
        if(u[mask ^ ((1<<(m-st)) - 1)] == T) continue;
        cout << "YES\n";
        cout << ans;
        for(int i = m-1; i >= st; i--) {
            if(mask&(1<<(i-st))) cout << 1;
            else cout << 0;
        }
        cout << "\n";
        return;
    }
    cout <<"NO\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}