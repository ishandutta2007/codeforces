#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

vector <vector <int>> gr;
vector <bool> used;

void bfs(int st) {
    deque <int> d;
    d.pb(st);
    used[st] = 1;
    while (!d.empty()) {
        int v = d[0];
        d.pop_front();
        //used[v] = 1;
        for (auto u : gr[v]) {
            if (!used[u]) {
                cout << v + 1 << " " << u + 1 << "\n";
                d.pb(u);
                used[u] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n), used.resize(n);
    forn (i, 0,m) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        gr[t1].pb(t2), gr[t2].pb(t1);
    }
    int mx = -1, v;
    forn (i, 0, n)
        if ((int)gr[i].size() > mx)
            //cout << gr[i].size() << " ";
            mx = gr[i].size(), v = i;
    //cout << v << "\n";
    bfs(v);
    return 0;
}