#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int p[maxn];
int t[maxn];
int l[maxn], r[maxn];
int ans[maxn];
int pos[maxn];
vector<int> q[maxn];
vector<int> g[maxn];
void upd(int pos, int val) {
    while(pos <= n) {
        t[pos] += val;
        pos |= pos + 1;
    }
}
int get(int pos) {
    int res = 0;
    while(pos >= 0) {
        res += t[pos];
        pos = (pos&(pos+1)) - 1;
    }
    return res;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j+= i) {
            int x = min(pos[i], pos[j]);
            int y = max(pos[i], pos[j]);
            g[y].emplace_back(x);
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        q[r[i]].emplace_back(i);
    }
    for(int i = 1; i <= n; i++) {
        for(int to: g[i]) {
            upd(to, 1);
        }
        for(int id: q[i]) {
            ans[id] = get(r[id]) - get(l[id] - 1);
        }
    }
    for(int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
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