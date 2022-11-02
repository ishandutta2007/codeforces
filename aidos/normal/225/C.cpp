#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;

int n, m, x, y;
int dp[maxn][2];
string s;
int a[maxn];
int sum[maxn];
int cost(int l, int r, int id) {
    int len = r-l;
    int val = sum[r] - sum[l];
    if(id) return val;
    return len * n - val;
}
int get(int pos, int id) {
    if(pos < 0) return inf;
    if(pos == 0) return 0;
    int &res = dp[pos][id];
    if(res != -1) return res;
    res = inf;
    for(int l = pos-1; l >= 0; l--) {
        if(pos - l >= x && pos - l <= y) {
            res = min(res, get(l, id^1) + cost(l, pos, id));
        }
    }
    return res;
}

void solve() {
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '#') a[j+1]++;
        }
    }
    for(int i = 1; i <= m; i++) {
        sum[i] = sum[i-1] + a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << min(get(m, 0), get(m, 1)) << "\n";
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