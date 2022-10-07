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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;

struct Ans {
    int x, y, y1;
};

int n;
vector<vector<int>> e;
void read() {
    scanf("%d", &n); 
    e.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

vector<Ans> solve() {
    vector<int> c(n);
    
    vector<int> cent;
    function<void(int, int)> dfs0 = [&](int v, int p) {
        c[v] = 1;
        int mx = 0;
        for (auto u: e[v]) {
            if (u == p) continue;
            dfs0(u, v);
            mx = max(mx, c[u]);
            c[v] += c[u];
        }
        mx = max(mx, n - c[v]);
        //db3(v, c[v], mx);
        if (mx * 2 <= n)
            cent.pb(v);
    };
    //db("!");
    dfs0(0, -1);
    //db(sz(cent));
    //db(cent[0]);
    assert(sz(cent) == 1 || sz(cent) == 2);

    vector<set<int>> g(n);
    for (int i = 0; i < n; i++) {
        g[i] = set<int>(all(e[i]));
    }

    vector<Ans> answer;
    auto remove = [&](int v, int u) {
        assert(g[v].erase(u));
        assert(g[u].erase(v));
    };

    auto add = [&](int v, int u) {
        assert(g[v].insert(u).S);   
        assert(g[u].insert(v).S);   
    };
    
    auto op = [&](int x, int y, int y1) {
        //db3(x, y, y1);
        if (y == y1) {
            //db3(x, y, "skip");
            return;
        }
        answer.pb({x, y, y1});
        remove(x, y);
        add(x, y1);
    };

    function<pair<int,int>(int, int)> dfs2 = [&](int v, int p) {
        vector<pair<int,int>> ch;
        for (auto u: e[v]) {
            if (u == p) continue;
            ch.pb(dfs2(u, v));
        }
         
        if (ch.size() == 1) { return make_pair(v, ch[0].S); }
        int curV = p;
        for (int i = 0; i < sz(ch) - 1; i++) {
            op(curV, v, ch[i].S);
            curV = ch[i].F;
        }
        if (ch.empty()) return make_pair(v, v);
        return make_pair(ch[0].S, ch.back().S);
    };
     
    forn(tt, sz(cent)) {
        int v = cent[tt];
        for (auto u: e[v]) {
            if (u == cent[(tt + 1) % sz(cent)]) continue;
            //db2(u, v);
            dfs2(u, v);
        }
    }
    //db("second part"); db(answer.size());

    forn(tt, sz(cent)) {
        int v = cent[tt];
        vector<int> local(all(g[v]));
        for (auto u: local) {
            if (u == cent[(tt + 1) % sz(cent)]) continue;
            //db2(v + 1, u + 1);
            vector<int> tmp;
            int x = v;
            int y = u;
            tmp.pb(v);
            for (;;) {
                //db2(x + 1, y + 1);
                tmp.pb(y);
                assert(g[y].size() <= 2);
                if (g[y].size() == 1) 
                    break;
                int nx = -1;
                for (auto z: g[y]) {
                    if (z != x)
                        nx = z;
                }
                assert(nx != -1);
                x = y;
                y = nx; 
            }
            //db("!", tmp);
            for (int i = sz(tmp) - 4; i >= 0; i--) {
                op(tmp[i], tmp[i + 1], tmp[sz(tmp) - 2]);    
            }
        }
    }

 


    //db(answer.size());
    //db(answer.size());
    assert(sz(answer) <= n * 2);
    return answer;
}

void printAns(vector<Ans> answer) {
    printf("%d\n", sz(answer));
    for (auto A: answer) {
        printf("%d %d %d\n", A.x + 1, A.y + 1, A.y1 + 1);
    }
}


void genTest() {
    n = rand() % 200 + 1;
    if (n % 2 == 0) 
        n++;
        
    e.clear();
    e.resize(n);
    vector<int> perm(n);
    forn(i, n) perm[i] = i;
    random_shuffle(all(perm));
    cerr << "----------------" << endl;
    cerr << n << endl;
    for (int i = 1; i < n; i++) {
        int p = rand() % i;
        int v = perm[p];
        int u = perm[i];
        e[v].pb(u);
        e[u].pb(v);
        cerr << v + 1 << " " << u + 1 << endl;
    }
}

void check(vector<Ans> res) {

    vector<set<int>> g(n);

    auto remove = [&](int v, int u) {
        assert(g[v].erase(u));
        assert(g[u].erase(v));
    };

    auto add = [&](int v, int u) {
        assert(g[v].insert(u).S);   
        assert(g[u].insert(v).S);   
    };
 

    for (int i = 0; i < n; i++) {
        g[i] = set<int>(all(e[i]));
    }
    for (auto A: res) {
        remove(A.x, A.y);
        add(A.x, A.y1);
    }
    //for (int i = 0; i < n; i++) {
        //for (auto u: e[i]) {
            //if (u < i) {
                //db2(u + 1, i + 1);
            //}
        //}
    //}
    vector<int> dist;
    auto bfs = [&](int st) {
        dist.assign(n, INF);
        dist[st] = 0; 
        queue<int> q;
        q.push(st);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u: g[v]) {
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] > dist[mx]) {
                mx = i;
            }
        } 
        return mx;
    };
    int top = bfs(0);
    dbv(dist);
    int t2 = bfs(top);
    db2(top, t2);
    db(dist[t2]);
    assert(dist[t2] <= 4);

}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    //freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        read();
        auto res = solve();
        printAns(res);
        //check(res);
    }
    else {
        for (int it = 0;;it++) {
            db(it);
            genTest();
            auto res = solve();
            check(res);
        }
    }
    


    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}