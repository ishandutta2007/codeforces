#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = (1 << 19) + 9;
#define SZ(x) int((x).size())
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)


vector<pii> e;
vi adj[N];
void clear (int n) { e.clear(); REP(i,0,n) adj[i].clear(); }
void add_edge (int a, int b) { adj[a].push_back(SZ(e)); adj[b].push_back(SZ(e)); e.push_back(pii(a,b)); }
vi euler_undirected (int n) {
    int start = -1, odddeg = 0;
    REP(i,0,n) {
        if (SZ(adj[i]) & 1) odddeg++, start = i;
        else if (!adj[i].empty() && start == -1) start = i;
    }
    if (odddeg > 2) return vi();
    vector<bool> used(SZ(e),0); // usage of edges
    vi stack, res, which(n+1,0); // which edge will be processed now
    stack.push_back(start);
    while (!stack.empty()) {
        int v = stack.back();
        while (which[v] < (int)(adj[v].size()) && used[adj[v][which[v]]]) ++which[v];
        if (which[v] == SZ(adj[v])) { // back out
            stack.pop_back();
            res.push_back(v);
        } else {
            int ed = adj[v][which[v]];
            int w = e[ed].first == v ? e[ed].second : e[ed].first;
            used[ed] = 1;
            stack.push_back(w);
        }
    }
    if (count(used.begin(), used.end(),0)) return vi(); // graph is not connected
    if(res[0] != res.back())
        return vi();
    return res;
}




int n;
int a[N];
int b[N];


vi f(int mask, bool get_ans) {
    mask = (1 << mask) - 1;

    static int idMp[1 << 20];
    fill(idMp, idMp + mask + 1, -1);

    map<pii, vector<pii>> edgesMp;

    for(int i = 1; i <= n; ++i) {
        idMp[a[i]&mask] = 1;
        idMp[b[i]&mask] = 1;
    }

    int nNodes = 0;

    for(int x = 0; x <= mask; ++x)
        if(idMp[x] != -1)
            idMp[x] = nNodes++;

        if(nNodes > N - 5) {

            return vi();
        }
    clear(nNodes);

    for(int i = 1; i <= n; ++i) {
        const int x = idMp[a[i]&mask];
        const int y = idMp[b[i]&mask];
        assert(x != -1 && y != -1);
        add_edge(x, y);
        if(get_ans) {
            edgesMp[pii{x, y}].emplace_back(2 * i - 1, 2 * i);
            if(x != y)
                edgesMp[pii{y, x}].emplace_back(2 * i, 2 * i - 1);
        }
    }

    vi v = move(euler_undirected(nNodes));
    if(v.empty()) {
        assert(!get_ans);
        return v;
    }

    if(!get_ans)
        return {0};

    vi res;
    for(int i = 0; i + 1 < (int)v.size(); ++i) {
        const int x = v[i];
        const int y = v[i+1];

        auto &&vp = edgesMp.at(pii{x, y});
        assert(!vp.empty());
        res.push_back(vp.back().first);
        res.push_back(vp.back().second);
        vp.pop_back();

        if(x != y) {
            auto &&vp2 = edgesMp.at(pii{y, x});
            assert(!vp2.empty());
            vp2.pop_back();
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];

//
//    {
//        auto res = f(3, false);
//        DBG(res.size());
//    }
    int lo = 0;
    int hi = 20;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        auto res = f(mid, false);
        if(!res.empty())
            lo = mid;
        else
            hi = mid - 1;
    }


    auto res = move(f(lo, true));

    cout << lo << '\n';
    for(int x : res)
        cout << x << ' ';

    return 0;
}