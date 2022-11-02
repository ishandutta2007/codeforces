#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;
string s;
int n;
int u[5202][5202];
int ok[5202];
int dp[5202];
void calc(vector<int> &cur) {
    int last[2] = {-1, -1};
    for(int i = 0; i < n; i++) {
        if(cur[i] == 0) {
            dp[i] = last[1];
            last[0] = i;
        } else {
            dp[i] = last[0];
            last[1] = i;
        }
    }
    for(int x = 1; x <= n; x++) {
        if(ok[x] == 0) continue;
        for(int j = x-1; j < n; j += x) {
            if(dp[j] > j - x) {
                ok[x] = 0;
            }
        }
    }
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            int v;
            if(s[j] >= '0' && s[j] <= '9') v = s[j] - '0';
            else v = s[j] - 'A' + 10;
            for(int k = 0; k < 4; k++) {
                if(v & (1<<(k))) u[i][j * 4 + 3-k] = 1;
                else u[i][j * 4 + 3-k] = 0;
            }
        }
    }

    for(int x = 1; x <= n; x++) {
        if(n % x == 0) ok[x] = 1;
        else ok[x] = 0;
    }
    vector<int> cur;
    for(int i = 0; i < n; i++) {
        cur.clear();
        for(int j = 0; j < n; j++) {
            cur.emplace_back(u[i][j]);
        }
        calc(cur);
        cur.clear();
        for(int j = 0; j < n; j++) {
            cur.emplace_back(u[j][i]);
        }
        calc(cur);
    }
    for(int i = n; i >= 1; i--) {
        if(ok[i]) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}