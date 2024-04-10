#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 100005;

vi g[N];
int f[N];
int ans[N];

void dfs(int cur) {
    ans[cur] = f[cur] % 2;
    for (int e: g[cur]) {
        f[e] += f[cur];
        dfs(e);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    stack<pair<int, ii>> st;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        st.push({i, {x, y}});
    }
    while (st.size() >= 3) {
        vector<pair<int, ii>> v(3);
        v[0] = st.top(); st.pop();
        v[1] = st.top(); st.pop();
        v[2] = st.top(); st.pop();
        vector<ii> a;
        for (int i = 0; i < 3; i++) {
            a.pb({i, -1});
            a.pb({i, 1});
        }
        bool flag = 0;
        int id1, id2;
        ii res = {0, 0};
        for (int i = 0; i < 6; i++) {
            for (int j = i + 1; j < 6; j++) {
                if (a[i].y == -1 && a[j].y == -1) continue;
                if (a[i].x == a[j].x) break;
                ii u = v[a[i].x].y;
                if (a[i].y == -1) u = {-u.x, -u.y};
                ii vv = v[a[j].x].y;
                if (a[j].y == -1) vv = {-vv.x, -vv.y};
                ii foo = {u.x + vv.x, u.y + vv.y};
                if (1LL * foo.x * foo.x + 1LL * foo.y * foo.y <= 1e12) {
                    flag = 1;
                    id1 = v[a[i].x].x;
                    id2 = v[a[j].x].x;
                    res = foo;
                    if (a[i].y == -1) swap(id1, id2);
                    if (a[i].y == -1 || a[j].y == -1) {
                        f[id2]++;
                    }
                    break;
                }
            }
            if (flag) break;
        }
        g[id1].pb(id2);
        st.push({id1, res});
        for (int i = 0; i < 3; i++) {
            if (v[i].x != id1 && v[i].x != id2) st.push(v[i]);
        }
    }
    auto v0 = st.top(); st.pop();
    auto v1 = st.top(); st.pop();
    ii foo = {v0.y.x + v1.y.x, v0.y.y + v1.y.y};
    if (1LL * foo.x * foo.x + 1LL * foo.y * foo.y > 2e12) {
        f[v1.x]++;
    }
    g[v0.x].pb(v1.x);
    dfs(v0.x);
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1) cout << -1 << ' ';
        else cout << 1 << ' ';
    }
    return 0;
}