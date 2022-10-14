#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, lli>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define X first
#define Y second
#define test(args...) abc("[" + string(#args) + "]", args)
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; l++) cout << *l << " \n"[l + 1 == r];
}
const int N = 100000;

vector <int> adj[N];
int day[N];
lli weight[N];
multiset <pii> s[N];

void dfs(int v) {
    for (int u : adj[v]) {
        dfs(u);
        if (s[v].size() < s[u].size())
            swap(s[v], s[u]);
        for (pii A : s[u]) {
            auto it = s[v].lower_bound(mp(A.X, -1));
            if (it != s[v].end() && it->X == A.X) {
                lli x = it->Y;
                s[v].erase(it), s[v].insert(mp(A.X, x + A.Y));
            } else {
                s[v].insert(A);
            }
        }
    }
    if (day[v]) {
        if (s[v].empty() || (--s[v].end())->X < day[v]) {
            s[v].insert(mp(day[v], weight[v]));
        } else {
            auto it_b = s[v].lower_bound(mp(day[v], -1));
            lli x = 0;
            if (it_b != s[v].end() && it_b->X == day[v])
                x = it_b->Y, s[v].erase(it_b), it_b = s[v].lower_bound(mp(day[v], -1));
            lli pre = 0;
            vector <pii> del;
            for (auto it = it_b; it != s[v].end(); ++it) {
                if (pre + it->Y <= weight[v]) {
                    del.pb(*it);
                    pre += it->Y;
                } else {
                    s[v].insert(mp(it->X, it->Y - weight[v] + pre));
                    s[v].erase(it);
                    break;
                }
            }
            for (pii A : del)
                s[v].erase(s[v].lower_bound(A));
            s[v].insert(mp(day[v], x + weight[v]));
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 1, p; i < n; ++i) {
        cin >> p, --p;
        adj[p].pb(i);
    }
    for (int i = 0, v, d, w; i < m; ++i) {
        cin >> v >> d >> w, --v;
        day[v] = d, weight[v] = w;
    }
    dfs(0);
    lli ans = 0;
    for (pii A : s[0])
        ans += A.Y;
    cout << ans << endl;
}