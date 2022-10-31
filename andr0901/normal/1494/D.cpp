//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int n;
vector<vector<int>> gr;

struct Node {
    int id, val;
    vector<int> children;

    Node(int _id = 0, int _val = 0, vector<int> _children = vector<int>()) 
        : id(_id), val(_val), children(_children) {}
};

vector<Node> nodes;
vector<vector<int>> children;

int lst_idx;

void solve(vector<int>& leaves, int root) {
    cerr << leaves << " " << root << "\n";
    if (leaves.size() == 0) {
        return;
    }
    if (leaves.size() == 1) {
        int i = nodes.size();
        nodes.pb(Node());
        nodes[i].id = leaves[0];
        nodes[i].val = gr[leaves[0]][leaves[0]];
        nodes[root].children.pb(i);
        return;
    }
    int mx = -1;
    for (int x : leaves) {
        if (gr[leaves[0]][x] > mx) {
            mx = gr[leaves[0]][x];
        }
    }
    if (root == -1 || mx != nodes[root].val) {
        int i = nodes.size();
        nodes.pb(Node(++lst_idx, mx));
        if (root != -1)
            nodes[root].children.pb(i);
        solve(leaves, i);
        return;
    }
    vector<int> l, r;
    for (int x : leaves) {
        if (gr[leaves[0]][x] == mx) {
            r.pb(x);
        } else {
            l.pb(x);
        }
    }
    solve(l, root);
    solve(r, root);
}

vector<int> values;
vector<pii> edges;

void dfs(int id, int id_p) {
    if (id == -1)
        return;
    int v = nodes[id].id;
    if (id_p != -1) {
        int p = nodes[id_p].id;
        edges.eb(v, p);
    }
    values[v] = nodes[id].val;
    for (int id_u : nodes[id].children)
        dfs(id_u, id);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    gr.resize(n, vector<int> (n));
    cin >> gr;
    lst_idx = n - 1;
    vector<int> leaves(n);
    iota(all(leaves), 0);
    Node tmp = Node(-1, -1, {});
    solve(leaves, -1);
    forn (i, 0, sz(nodes))
        cerr << nodes[i].id << " " << nodes[i].val << " " << nodes[i].children<< "\n";
    values.resize(lst_idx + 1);
    dfs(0, -1);
    cout << lst_idx + 1 << "\n";
    cout << values << "\n";
    cout << nodes[0].id + 1 << "\n";
    for (auto [v, u] : edges)
        cout << v + 1 << " " << u + 1 << "\n";
    return 0;
}