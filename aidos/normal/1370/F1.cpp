#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n;
vector<int> g[maxn];
int path[maxn];
pair<int, int> ask(vector<int> v) {
    cout << "? " << v.size();
    for(int x: v) cout << " " << x;
    cout << endl;
    pii ans;
    cin >> ans.first >> ans.second;
    return ans;
}

void dfs1(int v, int pa, int dis, vector<int> &a) {
    if(dis == 0) {
        a.emplace_back(v);
        return;
    }
    for(int to: g[v]) {
        if(to == pa) continue;
        if(path[to]) continue;
        dfs1(to, v, dis-1, a);
    }
}

int dfs2(int v, int pa, int f, int s) {
    if(path[v]) {
        if(f == v) return 1;
        return 2;
    }
    for(int to: g[v]) {
        if(to == pa) continue;
        int cur = dfs2(to, v, f, s);
        if(cur != 0) {
            path[v] = 1;
            return cur;
        }
    }
    return 0;
}

void solve() {
    cin >> n;
    vector<int> A;
    for(int i = 1; i <= n; i++) {
        path[i] = 0;
        g[i].clear();
        A.emplace_back(i);
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    pii cur = ask(A);
    int dis = cur.second;
    int f = cur.first, s = cur.first;
    int D = cur.second;
    path[f] = 1;
    while(dis > 0) {
        int cur_dis = (dis + 1)/2;
        vector<int> ord;
        dfs1(f, -1, cur_dis, ord);
        if(f != s) dfs1(s, -1, cur_dis, ord);
        pii cur = ask(ord);
        assert(cur.second == D);
        int v = dfs2(cur.first, -1, f, s);
        if(v == 1) {
            swap(cur.first, f);
        }else {
            swap(cur.first, s);
        }
        dis -= cur_dis;
    }
    cout << "! " << f << " "<<s << endl;
    string ans;
    cin >> ans;
    assert(ans == "Correct");
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}