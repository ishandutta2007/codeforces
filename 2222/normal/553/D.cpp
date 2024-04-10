#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int n;
bool good[100500];
vector<int> adj[100500];
int power[100500];

int main() {
    int m, k;
    scanf("%d%d%d", &n, &m, &k);
    REP (i, n) good[i] = true;
    for (; k --> 0; ) {
        int x; scanf("%d", &x);
        good[x - 1] = false;
    }
    REP (i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    priority_queue<pair<double, int>> q;
    REP (x, n) {
        for (int y : adj[x])
            power[x] += good[y];
        q.push({(double)-power[x] / sz(adj[x]), x});
    }
    vector<int> res;
    double best = 0;
    int bestStart = 0;
    for (; q.size(); ) {
        auto t = q.top();
        q.pop();
        if (!good[t.Y]) continue;
        if (t.X < best) {
            best = t.X;
            bestStart = sz(res);
        }
        res.pb(t.Y);
        good[t.Y] = false;
        for (int x : adj[t.Y])
            if (good[x]) {
                --power[x];
                q.push({(double)-power[x] / sz(adj[x]), x});
            }
    }
    res.erase(res.begin(), res.begin() + bestStart);
    cout << sz(res) << endl;
    REP (i, sz(res)) {
        if (i) putchar(' ');
        printf("%d", res[i] + 1);
    }
    puts("");
    return 0;
}