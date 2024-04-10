#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 200000;
vector <int> adj[N];
int n;

vector <int> bfs(int v) {
    queue <int> q;
    vector <int> dis(n, 1 << 20);
    q.push(v);
    dis[v] = 0;
    while (q.size()) {
        v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (dis[u] > dis[v] + 1) {
                dis[u] = dis[v] + 1;
                q.push(u);
            }
        }
    }
    return dis;
}

int main () {
    int m, k, tmp;
    cin >> n >> m >> k;
    set <int> input;
    vector <int> input2;
    fop (i,0,k) cin >> tmp, input.insert(tmp - 1), input2.pb(tmp);
    bool is = false;
    sort(input2.begin(), input2.end());
    fop (i,0,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        if (input.count(u) and input.count(v)) is = true;
    }
    vector <int> d0 = bfs(0), dn = bfs(n - 1);
    if (is) {
        cout << d0[n - 1] << endl;
        return 0;
    }
    vector <pii> A;
    for (int i : input) A.eb(d0[i] - dn[i], i);
    sort(A.begin(), A.end());
    set <int, greater <int>> s1;
    int ans = 0;
    FOP (i,k,0) {
        if (i + 1 < k) s1.insert(dn[A[i + 1].Y]);
        if (s1.size()) ans = max(ans, d0[A[i].Y] + *s1.begin() + 1);
    }
    cout << min(ans, d0[n - 1]) << endl;
}