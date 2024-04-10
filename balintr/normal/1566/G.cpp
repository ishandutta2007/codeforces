#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 1e5 + 5;
int n, m, q;

struct Edge {
    int a, b;
    ll c;

    const inline bool operator<(const Edge &e) const {
        if(c != e.c) return c < e.c;
        if(min(a, b) != min(e.a, e.b)) return min(a, b) < min(e.a, e.b);
        return max(a, b) < max(e.a, e.b);
    }
};

set<Edge> globalSet, nodeSet[MN];
set<pii> adjList[MN];
set<pair<ll, int>> min3Set;

void removeMin3(int a){
    if(nodeSet[a].size() >= 3){
        ll sum = 0;
        auto iter = nodeSet[a].begin();
        sum += iter->c;
        sum += (++iter)->c;
        sum += (++iter)->c;
        min3Set.erase({sum, a});
    }
}

void addMin3(int a){
    if(nodeSet[a].size() >= 3){
        ll sum = 0;
        auto iter = nodeSet[a].begin();
        sum += iter->c;
        sum += (++iter)->c;
        sum += (++iter)->c;
        min3Set.insert({sum, a});
    }
}

void addEdge(int a, int b, int c){
    removeMin3(a);
    nodeSet[a].insert({a, b, c});
    adjList[a].insert({b, c});
    addMin3(a);
    bool goodA = nodeSet[a].size() <= 3;
    if(!goodA){
        auto iter = nodeSet[a].begin();
        for (int i = 0; i < 3; ++i) {
            if(iter->b == b) goodA = true;
            ++iter;
        }
        if(goodA) globalSet.erase({a, iter->b, iter->c});
    }

    removeMin3(b);
    nodeSet[b].insert({b, a, c});
    adjList[b].insert({a, c});
    addMin3(b);
    bool goodB = nodeSet[b].size() <= 3;
    if(!goodB){
        auto iter = nodeSet[b].begin();
        for (int i = 0; i < 3; ++i) {
            if(iter->b == a) goodB = true;
            ++iter;
        }
        if(goodB) globalSet.erase({b, iter->b, iter->c});
    }

    if(goodA && goodB){
        globalSet.insert({a, b, c});
    }
}

void removeEdge(int a, int b, int c){
    globalSet.erase({a, b, c});
    removeMin3(a);
    nodeSet[a].erase({a, b, c});
    adjList[a].erase({b, c});
    addMin3(a);
    if(nodeSet[a].size() >= 3){
        auto iter = nodeSet[a].begin();
        ++iter; ++iter;
        int o = iter->b;

        bool good = nodeSet[o].size() <= 3;
        if(!good){
            auto iter1 = nodeSet[o].begin();
            for (int i = 0; i < 3; ++i) {
                if(iter1->b == a) good = true;
                ++iter1;
            }
        }

        if(good) globalSet.insert({a, iter->b, iter->c});
    }

    removeMin3(b);
    nodeSet[b].erase({b, a, c});
    nodeSet[b].erase({a, c});
    addMin3(b);
    if(nodeSet[b].size() >= 3){
        auto iter = nodeSet[b].begin();
        ++iter; ++iter;
        int o = iter->b;

        bool good = nodeSet[o].size() <= 3;
        if(!good){
            auto iter1 = nodeSet[o].begin();
            for (int i = 0; i < 3; ++i) {
                if(iter1->b == b) good = true;
                ++iter1;
            }
        }

        if(good) globalSet.insert({b, iter->b, iter->c});
    }
}

void query(){
    ll best = min3Set.empty() ? LLINF : min3Set.begin()->fs;
    assert(best > 0);
    if(globalSet.empty()) for(;;);
    Edge mEdge = *globalSet.begin();

    for(Edge e : globalSet){
        if(e.a != mEdge.a && e.a != mEdge.b && e.b != mEdge.a && e.b != mEdge.b){
            best = min(best, mEdge.c + e.c);
            break;
        }
    }

    vector<Edge> edges;

    auto iter = nodeSet[mEdge.a].begin();
    for (int i = 1; i < 3 && i < nodeSet[mEdge.a].size(); ++i) {
        edges.pb(*++iter);
    }

    iter = nodeSet[mEdge.b].begin();
    for (int i = 1; i < 3 && i < nodeSet[mEdge.b].size(); ++i) {
        ++iter;
        int a = mEdge.b;
        int b = iter->b;
        ll c = iter->c;
        for(Edge e : edges){
            if(a != e.a && a != e.b && b != e.a && b != e.b){
                best = min(best, c + e.c);
            }
        }
    }

    assert(best > 0);
    cout << best << '\n';
}

int main(){
    boost();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    cin >> q;
    query();
    while(q--){
        int type, a, b, c;
        cin >> type >> a >> b;

        if(type == 0){
            c = adjList[a].lower_bound({b, 0})->sn;
            removeEdge(a, b, c);
        }
        else {
            cin >> c;
            addEdge(a, b, c);
        }
        query();
    }
}