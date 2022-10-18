//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

template<typename Edge>
class GraphIterator {
public:
    class OutgoingEdges {
    public:
        OutgoingEdges(const GraphIterator *g, int l, int r): g(g), l(l), r(r) {
        }

        const Edge* begin() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[l];
        }

        const Edge* end() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[r];
        }

    private:
        int l, r;
        const GraphIterator *g;
    };

    void clear() {
        prepared_edges.clear();
        edges.clear();
        start.clear();
        prepared = false;
    }

    void add_edge(int from, const Edge &e) {
        assert(!prepared && from >= 0);
        edges.push_back({from, e});
    }

    void prepare() {
        assert(!prepared);
        int n = 0;
        for (const auto &e : edges) {
            n = max(n, e.first);
        }
        n += 2;
        start.resize(n);
        for (const auto &e : edges) {
            ++start[e.first + 1];
        }
        for (int i = 1; i < n; ++i) {
            start[i] += start[i - 1];
        }
        prepared_edges.resize(edges.size() + 1);
        auto counter = start;
        for (const auto &e : edges) {
            prepared_edges[counter[e.first]++] = e.second;
        }
        prepared = true;
    }

    OutgoingEdges operator [] (int from) const {
        assert(prepared);
        if (from < 0 || from + 1 >= start.size()) {
            return {this, 0, 0};
        }
        return {this, start[from], start[from + 1]};
    }

private:
    vector<Edge> prepared_edges;
    vector<pair<int, Edge>> edges;
    vector<int> start;
    bool prepared = false;
};

class two_sat {
public:
    two_sat(int n): answer(n, -1) {
    }

    void add_or_clause(int x, bool valx, int y, bool valy) {
        x = x * 2 + valx;
        y = y * 2 + valy;
        g.add_edge(x ^ 1, y);
        g.add_edge(y ^ 1, x);
    }

    pair<bool, vector<int>> solve() {
        g.prepare();
        for (int i = 0; i < answer.size(); ++i) {
            if (answer[i] == -1) {
                lastv.clear();
                if (!dfs(2 * i)) {
                    for (int v : lastv) {
                        answer[v] = -1;
                    }
                    if (!dfs(2 * i + 1)) {
                        return {false, {}};
                    }
                }
            }
        }
        return {true, answer};
    }

private:
    bool dfs(int v) {
        lastv.push_back(v / 2);
        answer[v / 2] = v % 2;
        for (int to : g[v]) {
            if ((answer[to / 2] != -1 && answer[to / 2] != to % 2) || (answer[to / 2] == -1 && !dfs(to))) {
                return false;
            }
        }
        return true;
    }

    vector<int> answer, lastv;
    GraphIterator<int> g;
};

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n,m;
        cin>>n>>m;
        two_sat solver(n);

        auto add_kek=[&](int u,int v,int type)
        {
            if (type==0){
                solver.add_or_clause(u,0,v,1);
                solver.add_or_clause(u,1,v,0);
            }
            else{
                solver.add_or_clause(u,0,v,0);
                solver.add_or_clause(u,1,v,1);
            }
        };

        vector<pair<pii,int>> edges;
        for (int i=1;i<n;i++){
            int u,v,c;
            cin>>u>>v>>c;
            u--;
            v--;
            if (c!=-1){
                int type=__builtin_popcountll(c)%2;
                add_kek(u,v,type);
            }
            edges.pb(mp(mp(u,v),c));
        }
        for (int i=0;i<m;i++){
            int u,v,c;
            cin>>u>>v>>c;
            u--;
            v--;
            int type=__builtin_popcountll(c)%2;
            add_kek(u,v,type);
        }
        pair<bool, vector<int>> ans = solver.solve();
        if (!ans.fir){
            cout<<"NO"<<"\n";
            continue;
        }
        cout<<"YES"<<"\n";
        for (auto& i:edges){
            if (i.sec==-1){
                i.sec=ans.sec[i.fir.fir]^ans.sec[i.fir.sec];
            }
        }
        for (auto i:edges){
            cout<<i.fir.fir+1<<" "<<i.fir.sec+1<<" "<<i.sec<<"\n";
        }
    }
}