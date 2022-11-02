#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e2 + 10;
const int mod = (int)998244353;
const int inf = (1<<30) - 1;
int n, m;
string s[maxn];
int d[maxn][maxn];
int a[1000100];
int dp[1000100];
int last[1000100];
int pr[1000100];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) d[i][j] = 0;
            else if(s[i][j] == '1') d[i][j] = 1;
            else d[i][j] = inf;
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    cin >> m;
    for(int i = 0; i<m; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    vector<int> ans;
    dp[0] = 0;
    pr[0] = -1;
    for(int i = 0; i < n; i++) last[i] = -1;
    last[a[0]] = 0;
    for(int i = 1; i < m; i++) {
        int v = a[i];
        int &res = dp[i];
        res = inf;
        for(int j = 0; j < n; j++) {
            if(last[j] == -1) continue;
            if(i-last[j] == d[j][v]) {
                if(res > dp[last[j]] + 1) {
                    res = dp[last[j]] + 1;
                    pr[i] = last[j];
                }
            }
        }
        last[v] = i;
    }
    int v = m-1;
    while(v >= 0) {
        ans.push_back(a[v]);
        v = pr[v];
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for(const int &v: ans) printf("%d ", v+1);

}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}