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

struct Node {
    int u, correct, idx;
};

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    cin >> a >> b;
    vector <vector <Node>> gr(n);
    forn (i, 0, n) {
        a[i]--, b[i]--;
        int v = a[i], u = b[i];
        //cerr << v << " " << u << "\n";
        gr[v].pb({u, 0, i});
        gr[u].pb({v, 1, i});
    }
    forn (i, 0, n) {
        if (gr[i].size() != 2) {
            cout << "-1\n";
            return;
        }
    }
    vector <int> ans;
    vector <bool> used(n);
    forn (i, 0, n) {
        if (used[i])
            continue;
        vector <Node> cycle;
        int v = i, p = gr[v][0].u;
        set <int> distinct;
        for (auto x : gr[v])
            distinct.insert(x.u);
        if (distinct.size() == 1) {
            int u = *distinct.begin();
            used[v] = used[u] = true;
            if (u == v)
                continue;
            cycle.pb(gr[v][0]), cycle.pb(gr[u][1]);
        } else {
            do {
               cerr << v << " ";
                used[v] = true;
                int nxt = -1;
                for (auto x : gr[v])
                    if (x.u != p) {
                        nxt = x.u;
                        cycle.pb(x);
                    }
                p = v;
                v = nxt;
            } while (v != i && v != -1);
        }
        int wrong = 0;
        forn (i, 0, sz(cycle))
            if (!cycle[i].correct)
                wrong++;
        cerr << ":" << sz(cycle) << " " << wrong << "\n";
        if (wrong > sz(cycle) - wrong) {
            forn (i, 0, sz(cycle))
                if (cycle[i].correct)
                    ans.pb(cycle[i].idx);
        } else {
            forn (i, 0, sz(cycle))
                if (!cycle[i].correct)
                    ans.pb(cycle[i].idx);
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}