#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int nxt[(1<<19) * 19][2];
unordered_map<int, int> dp[1<<19];
int sz = 1;
void add(int x) {
    int v = 1;
    for(int i = k-1; i >= 0; i--) {
        int bi = (x>>i)&1;
        if(nxt[v][bi] == 0) {
            nxt[v][bi] = ++sz;
        }
        v = nxt[v][bi];
    }
}
int getR(int mask, int v, int k) {
    int res = 0;
    for(int i = k; i >= 0; i--) {
        int bi = (mask>>i)&1;

        if(nxt[v][bi^1] == 0) {
            v = nxt[v][bi];
        } else {
            v = nxt[v][bi^1];
            res ^= 1<<i;
        }
    }
    return res;
}
int getL(int mask, int v, int k) {
    int res = 0;

    for(int i = k; i >= 0; i--){
        int bi = (mask>>i)&1;

        if(nxt[v][bi] == 0) {
            v = nxt[v][bi^1];
            res ^= 1<<i;
        } else {
            v = nxt[v][bi];
        }
    }
    return res;
}
int get(int mask, int k, int v){
    if(k < 0)  return 1e9;
    if(dp[mask].count(v)) return dp[mask][v];
    dp[mask][v] = 0;
    int &res = dp[mask][v];
    int tt = (1<<(k)) - 1;
    if(nxt[v][0] == 0) {
        return res = get(mask&tt, k-1, nxt[v][1]);
    }
    if(nxt[v][1] == 0) {
        return res = get(mask&tt, k-1, nxt[v][0]);
    }
    res = min(get(mask&tt, k-1, nxt[v][1]), get(mask&tt, k-1, nxt[v][0]));

    if(mask & (1<<k)) {
        int t1 = getR(mask&tt, nxt[v][1], k-1);
        int t2 = getL(mask&tt, nxt[v][0], k-1);
        res = min(res, t2 + (1<<k) - t1);
    } else {
        int t1 = getR(mask&tt, nxt[v][0], k-1);
        int t2 = getL(mask&tt, nxt[v][1], k-1);
        res = min(res, t2 + (1<<k) -t1);
    }
    return res;
}
void print(int v) {
    if(v == 0) return;
    if(nxt[v][0]) cout << "(" << v << " " << nxt[v][0] << ")\n";
    if(nxt[v][1]) cout << "(" << v << " " << nxt[v][1] << ")\n";
    print(nxt[v][0]);
    print(nxt[v][1]);
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
    }
    //print(1);
    for(int i = 0; i < (1<<k); i++) {
        if(n > 99999){
            cout << 1 << " ";
            continue;
        }
        int res = get(i, k-1, 1);
        cout << res << " ";
    }
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}