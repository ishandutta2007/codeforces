#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vll = vector<ll>;

const int inf = 1e9+100;
const int nax = 500;

int n, m;
int dst[nax][nax];
bitset<nax> cand;
int vv;
string s;
vi g[nax];

inline void kek(int v) {
    cout << v + 1 << endl;
    cin >> s;
    vv = -1;
    if(s[0] == 'G') cin >> vv, vv--;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int k, u; cin >> k >> u; u--;
        for(int j = 1; j < k; j++) {
            int v; cin >> v; v--;
            g[u].pb(v); g[v].pb(u);
            u = v;
        }
    }
    for(int u = 0; u < n; u++) {
        memset(dst[u], -1, sizeof(dst[u]));
        dst[u][u] = 0;
        queue<int> q;
        q.push(u);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(dst[u][to] == -1) {
                    dst[u][to] = dst[u][v] + 1;
                    q.push(to);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cand.reset();
        for(int u = 0; u < n; u++) cand[u] = 1;
        while(cand.count() > 1) {
            int ov = -1, ow = inf;
            for(int u = 0; u < n; u++) if(cand[u]) {
                int oW = 0;
                for(int v : g[u]) {
                    int cnt = 0;
                    for(int to = 0; to < n; to++) {
                        if(cand[to] && dst[to][v] < dst[to][u]) {
                            cnt++;
                        }
                    }
                    oW = max(oW, cnt);
                }
                if(oW < ow) ov = u, ow = oW;
            }
            kek(ov);
            if(vv == -1) { cand.reset(); cand[ov] = 1; break; }
            for(int u = 0; u < n; u++) if(cand[u] && !(dst[u][vv] < dst[u][ov])) cand[u] = 0;
        }
        for(int u = 0; u < n; u++) if(cand[u]) kek(u);
    }
}