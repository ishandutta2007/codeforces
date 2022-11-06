#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORI(i, n) REP(i,1,n)
#define FOR(i, n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i, t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

// usage: clear(n), add_edge(a,b), euler_undirected(n) (G on vertices  0..n)
// OUT: no path -> vi(), path -> a vector of vertices, cycle -> v[0]==v.back()
#define N 300005
vector<pii > e;
vi adj[N];

void clear(int n) {
    e.clear();
    REP(i, 0, n) adj[i].clear();
}

void add_edge(int a, int b) {
    adj[a].pb(SZ(e));
    adj[b].pb(SZ(e));
    e.pb(pii(a, b));
}

vi euler_undirected(int n) {
    int start = -1, odddeg = 0;
    REP(i, 0, n) {
        if (SZ(adj[i]) & 1) odddeg++, start = i;
        else if (!adj[i].empty() && start == -1) start = i;
    }
    if (odddeg > 2) return vi();
    vector<bool> used(SZ(e), 0); // usage of edges
    vi stack, res, which(n + 1, 0); // which edge will be processed now
    stack.pb(start);
    while (!stack.empty()) {
        int v = stack.back();
        while (which[v] < SZ(adj[v]) && used[adj[v][which[v]]]) ++which[v]; // rewind the used edges
        if (which[v] == SZ(adj[v])) { // back out
            stack.pop_back();
            res.pb(v);
        } else {
            int ed = adj[v][which[v]];
            int w = e[ed].fi == v ? e[ed].se : e[ed].fi;
            used[ed] = 1;
            stack.pb(w);

        }
    }
    if (count(used.begin(), used.end(), 0)) return vi(); // graph is not connected
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> b(n-1), c(n-1);
    for (int &x : b)
        cin >> x;
    for (int &x : c)
        cin >> x;


    vector<int> v(b.begin(), b.end());
    v.insert(v.end(), c.begin(), c.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int &x : b)
        x = lower_bound(v.begin(), v.end(), x) - v.begin();
    for (int &x : c)
        x = lower_bound(v.begin(), v.end(), x) - v.begin();


    for (int i = 0; i < n - 1; ++i) {
        if (b[i] > c[i]) {
            cerr << "less" << endl;
            cout << -1 << endl;
            return 0;
        }
        add_edge(b[i], c[i]);
    }

    const vector<int> res = euler_undirected((int)v.size());
    if(res.empty()) {
        cerr << "empty" << endl;
        cout << -1 << endl;
        return 0;
    }
    for(int x : res)
        cout << v[x] << ' ' ;

    return 0;
}