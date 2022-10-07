#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 55;
const int INF = 1.01e9;
typedef vector<int> vi;


struct State {
    int v, u, x, y;
    bool operator < (State A) const {
        return vect() < A.vect();
    }
    vector<int> vect() const {
        return {v, u, x, y};
    }
    void Epr() {
        cerr << "v u x y: " << v << " " << u << " " << x << " " << y << endl;
    }
};

map<State,int> q;
vector<pair<int,int>> e[N];
map<pair<int,int>,int> costE;

int go(State st) {
    assert(st.x >= 0 && st.y >= 0);
    //st.Epr();
    if (st.x == 0) {
        //assert(false);
        assert(st.y > 0);
        return INF;
    }
    auto it = q.find(st);
    if (it == q.end()) {
        int v = st.v;
        int u = st.u;
        int x = st.x;
        int y = st.y;
        int sum = x + y;
        int& answer = q[st];
        if (e[u].size() == 1) {
            if (y == 0) {
                answer = e[u][0].S;
            }
            else {
                answer = go({u, v, y, 0}) + e[u][0].S;
            }
        } 
        else if (e[u].size() == 2) {
            int other = e[u][0].F + e[u][1].F - v;
            answer = go({u, other, x, y}) + costE[make_pair(v, u)];
        }
        else {
            vector<pair<int,int>> ch;
            for (auto h: e[u]) {
                if (h.F != v) {
                    ch.pb(h);
                }
            }
            vector<vector<int>> preCalc(ch.size(), vector<int>(st.x + 1));
            set<pair<int,int>> w;
            forn(i, ch.size()) {
                w.insert({go({u, ch[i].F, 1, sum - 1}), i});
            }
            int last = -1;
            vector<int> lastVal(ch.size(), 1);
            forn(_, x) {
                auto g = *w.rbegin();
                last = g.F;
                if (_ + 1 == x) 
                    break;
                assert(w.erase(g));
                lastVal[g.S]++;
                int superVal = go({u, ch[g.S].F, lastVal[g.S], sum - lastVal[g.S]});
                w.insert({superVal, g.S});
            }
            answer = last + costE[make_pair(v, u)];
        }
        return answer;
    }
    else {
        return it->S;
    }
}



int cnt[N];
bool use[N];

void dfs(int v) {
    use[v] = 1;
    for (auto x: e[v]) {
        int u = x.F;
        if (!use[u]) {
            dfs(u);
            cnt[v] += cnt[u];
        }
    }
}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    forn(i, n - 1) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w); v--; u--;
        e[v].pb({u, w});
        e[u].pb({v, w});
        costE[make_pair(v, u)] = w;
        costE[make_pair(u, v)] = w;
    } 

    
    int s;
    scanf("%d", &s); s--; 
    int m;
    scanf("%d", &m);
    forn(i, m) {
        int id;
        scanf("%d", &id); id--;
        cnt[id]++;
    }
    
    dfs(s);
    assert(cnt[s] == m);
    int answer = INF;
    for (auto x: e[s]) {
        answer = min(answer, go({s, x.F, cnt[x.F], m - cnt[x.F]}));
    }
    //db("!!!!!!!!!!!!!!!!!!");
    //db(go({1, 2, 1, 1}));
    //db("!!!!!!!!!!!!!!!!!!");
    //db(go({2, 1, 1, 0}));
    
    cout << answer << endl;






    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}