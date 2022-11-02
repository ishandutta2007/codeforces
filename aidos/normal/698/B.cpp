#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int p[maxn];
int u[maxn];
int F;
vector<int> pos;
void dfs(int v) {
    u[v] = 1;
    int t = p[v];
    if(u[t] == 0) {
        dfs(t);
    } else if(u[t] == 1 && F == 0){
        F = 1;
        pos.push_back(v);
    }
    u[v] = 2;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) {
        if(u[i]) continue;
        F = 0;
        dfs(i);
    }
    for(int i = 1; i < pos.size(); i++) {
        if(p[pos[i]] == pos[i]) swap(pos[i], pos[0]);
    }
    int v = pos[0];
    int cnt = 0;
    for(int i = 0; i < pos.size(); i++) {
        if(p[pos[i]] != v) {
            p[pos[i]] = v;
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(int i = 1; i <= n; i++) cout << p[i] << " ";
}


int main() {
    ios_base::sync_with_stdio(false);
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