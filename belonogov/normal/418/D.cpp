#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue> 
using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define left leftttt
#define right rightt

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1e5 + 10;
const int inf = 1e9;
const int T = 18;

struct Tree {
    vector < int > a;
    int size;
    Tree(){}
    void init(vector < int > & data) {
        size = data.size(); 
        a.clear();
        a.resize(size * 4);
        init2(0, 0, size, data); 
    }
    void init2(int v, int ll, int rr, vector < int > & data) {
        if (ll + 1 == rr) {
            a[v] = data[ll];
            return;
        }
        init2(v * 2 + 1, ll, (ll + rr) / 2, data);
        init2(v * 2 + 2, (ll + rr) / 2, rr, data);
        a[v] = max(a[v * 2 + 1], a[v * 2 + 2] + (ll + rr) / 2 - ll);
    }
    int getMax(int l, int r) {
        //epr("getMax l r: %d %d\n", l, r);
        return getMaxSeg(0, 0, size, l, r);
    }
    int getMaxSeg(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return -inf;
        if (l <= ll && rr <= r)
            return a[v];
        int r1, r2;
        r1 = getMaxSeg(v * 2 + 1, ll, (ll + rr) / 2, l, r);
        r2 = getMaxSeg(v * 2 + 2, (ll + rr) / 2, rr, l, r);
        //epr("v ll rr r1 r2:   %d   %d %d    %d %d\n", v, ll, rr, r1, r2);
        if (l < (ll + rr) / 2) {
            r2 += (ll + rr) / 2 - max(l, ll);
        }
        return max(r1, r2);
    }
};

vector < int > e[maxn];
int par0[maxn];
int distToPath[maxn];
int jump[maxn][T];
int tin[maxn];
int tout[maxn];
int H[maxn];
int goToRoad[maxn];
int idOnPath[maxn];
int firstChild[maxn];
pair < int, int > depth1[maxn];
pair < int, int > depth2[maxn];
vector < pair < int, int > > query;
vector < pair < int, int > > edges;
int longestPathInTree[maxn];
bool use[maxn];
bool onLongestPath[maxn];
pair < int, int > longestPath; 
vector < int > path;
vector < int > data;
Tree left;
Tree right;
int topPath = -1;
int ans;
int tmr;
int n, m;

pair < int, int > dfsLongestPath(int v) {
    pair < int, int > prT, pr1, pr2;
    pr1 = mp(0, v);
    pr2 = mp(0, v);
    use[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++) { if (!use[e[v][i]]) {
            prT = dfsLongestPath(e[v][i]);
            par0[e[v][i]] = v;
            if (pr2.fr < prT.fr) swap(prT, pr2);
            if (pr1.fr < pr2.fr) swap(pr1, pr2);
        }
    }
    //epr("pr %d %d\n", pr1.fr, pr2.fr);
    //epr("pr.sc %d %d\n", pr1.sc, pr2.sc);
    if (pr1.fr + pr2.fr > ans) {
        longestPath = mp(pr1.sc, pr2.sc);
        topPath = v;
        ans = pr1.fr + pr2.fr;
    }
    return mp(pr1.fr + 1, pr1.sc);
}

pair < int, int > dfs1(int v, int h, int p, int ch) {
    //cerr << "v h: " << v << " " << h << endl;
    int newCh;
    pair < int, int > tmp;
    use[v] = 1;
    distToPath[v] = h;
    depth1[v] = depth2[v] = mp(0, v);
    goToRoad[v] = p;
    firstChild[v] = ch;
    for (int i = 0; i < (int)e[v].size(); i++) {
        if (onLongestPath[e[v][i]]) continue;
        //cerr << "v -> to: " << v << " " << e[v][i] << endl;
        if (!use[e[v][i]]) {
            newCh = (ch == -1)? e[v][i]: ch;
            tmp = dfs1(e[v][i], h + 1, p, newCh);
            if (tmp.fr > depth2[v].fr) swap(tmp, depth2[v]);
            if (depth2[v].fr > depth1[v].fr) swap(depth1[v], depth2[v]);
        }
    }
    return mp(depth1[v].fr + 1, v);
}

void dfs2(int v, int wayUp) {
    int newWayUp;
    use[v] = 1;
    longestPathInTree[v] = max(depth1[v].fr, wayUp);
    for (int i = 0; i < (int)e[v].size(); i++) {
        if (onLongestPath[e[v][i]]) continue;
        if (!use[e[v][i]]) {
            if (depth1[v].sc == e[v][i])
                newWayUp = max(wayUp, depth2[v].fr);
            else 
                newWayUp = max(wayUp, depth1[v].fr);
            dfs2(e[v][i], newWayUp + 1);
        }
    }
}

void dfs3(int v, int p, int id) {
    use[v] = 1;
    if (id == 0)
        jump[v][id] = p;
    else 
        jump[v][id] = jump[jump[v][id - 1]][id - 1];
    for (int i = 0; i < (int)e[v].size(); i++)
        if (!use[e[v][i]])
            dfs3(e[v][i], v, id);
}

void dfs4(int v, int h) {
    tin[v] = tmr++;
    H[v] = h;
    use[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++)
        if (!use[e[v][i]])      
            dfs4(e[v][i], h + 1);
    tout[v] = tmr++;
}

bool checkPar(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLCA(int v, int u) {
    if (checkPar(v, u)) return v;
    if (checkPar(u, v)) return u;
    for (int i = T - 1; i >= 0; i--)
        if (!checkPar(jump[v][i], u))
            v = jump[v][i];
    return jump[v][0];
}

int getUp(int v, int k) {

    for (int i = T - 1; i >= 0; i--)
        if ((1 << i) <= k) {
            v = jump[v][i];
            k -= (1 << i);
        }
    return v;
}

int calc(int l, int r, int v) {
    //epr("l r v: %d %d %d\n", l, r, v);
    int idv;
    int n = path.size();
    idv = idOnPath[goToRoad[v]];
    int ans = 0;
    ans = longestPathInTree[v];
    //epr("ansNew2 %d\n", ans);
    if ((idv + 1) < (r) + 1)
        ans = max(ans, left.getMax((idv + 1), (r) + 1) + 1 + distToPath[v]);
    //epr("ansNew2 %d\n", ans);
    pair < int, int > pr = mp(l, idv - 1);
    pr = mp(n - pr.fr - 1, n - pr.sc - 1);
    pr = mp(pr.sc, pr.fr);
    if (pr.fr < pr.sc + 1)
        ans = max(ans, right.getMax(pr.fr, pr.sc + 1) + 1 + distToPath[v]);
    //epr("segTree %d\n", right.getMax(pr.fr, pr.sc + 1));
    //epr("ansNew2 %d\n", ans);
    return ans;
}

vector < int > solve() {
    int v, u;
    path.clear();
    for (int i = 0; i < n; i++)
        e[i].clear();
    for (int i = 0; i < (int)edges.size(); i++) {
        v = edges[i].fr;
        u = edges[i].sc;
        v--; u--;
        e[v].pb(u);
        e[u].pb(v);
        //cerr << "v u: " << edges[i].fr << " " << edges[i].sc << endl;
    }
   /* for (int i = 0; i < n; i++, cerr << endl) {
        for (int j = 0; j < (int)e[i].size(); j++)
            epr("%d ", e[i][j]);
    }*/
    memset(use, 0, sizeof(use));
    topPath = -1;
    ans = 0;
    dfsLongestPath(0);
    assert(topPath != -1);
    //epr("ends path: %d %d\n", longestPath.fr + 1, longestPath.sc + 1);
    memset(onLongestPath, 0, sizeof(onLongestPath));
    for (;longestPath.fr != topPath; longestPath.fr = par0[longestPath.fr]) {
        onLongestPath[longestPath.fr] = 1;
        path.pb(longestPath.fr);
    }
    vector < int > path1;
    for (;longestPath.sc != topPath; longestPath.sc = par0[longestPath.sc]) {
        onLongestPath[longestPath.sc] = 1;
        path1.pb(longestPath.sc);
    }    
    path.pb(topPath);
    onLongestPath[topPath] = 1;
    reverse(path1.begin(), path1.end());
    for (int i = 0; i < (int)path1.size(); i++)
        path.pb(path1[i]);
    //epr("path\n");
    //for (int i = 0; i < (int)path.size(); i++)
        //epr("%d ", path[i] + 1);
    //epr("\n");

    memset(use, 0, sizeof(use));
    memset(firstChild, 0, sizeof(firstChild));
    for (int i = 0; i < (int)path.size(); i++)
        dfs1(path[i], 0, path[i], -1); 
    memset(use, 0, sizeof(use));
    for (int i = 0; i < (int)path.size(); i++)
        dfs2(path[i], 0);
    //for (int i = 0; i < n; i++) {
        //epr("id distTopath: %d %d\n", i + 1, distToPath[i]);
    //}
    memset(idOnPath, 0, sizeof(idOnPath));
    for (int i = 0; i < (int)path.size(); i++)
        idOnPath[path[i]] = i;

/// lca
    for (int i = 0; i < T; i++) {
        memset(use, 0, sizeof(use));
        dfs3(path[0], path[0], i);
    }
    // in out
    memset(use, 0, sizeof(use));
    dfs4(path[0], 0);


/// lca
    data.resize(path.size());
    for (int i = 0; i < (int)path.size(); i++)
        data[i] = depth1[path[i]].fr;
    //epr("data\n");
    //for (int i = 0; i < (int)path.size(); i++)
        //epr("%d ", data[i]);
    //epr("\n");
    left.init(data);
    reverse(data.begin(), data.end());
    right.init(data); 
    int len, o, w, id;
    vector < int > solveAns;
    //cerr << "path\n";
    //for (int i = 0; i < (int)path.size(); i++)
     //   epr("%d ", path[i] + 1);
   /* epr("\n");
    cerr << "idonPath:\n";
    for (int i = 0; i < n; i++)
        cerr << idOnPath[i] << " ";
    cerr << endl;*/
    for (int i = 0; i < m; i++) {
        v = query[i].fr;
        u = query[i].sc;
        v--; 
        u--;
        o = getLCA(v, u); 
        len = H[v] + H[u] - H[o] * 2;
        //epr("len: %d\n", len);
        //epr("v u H[v] H[u] %d %d %d %d\n", v, u, H[v], H[u]);
        if (H[v] < H[u])
            swap(v, u);
        //epr("v u H[v] H[u] %d %d %d %d\n", v, u, H[v], H[u]);
        w = getUp(v, len / 2);
        //epr("w %d\n", w + 1);        
        bool flag = 0;
        if (onLongestPath[w]) {
            int idv, idu, idw;
            idv = idOnPath[goToRoad[v]];
            idu = idOnPath[goToRoad[u]]; 
            idw = idOnPath[w];
            //epr("idv idu idw %d %d %d\n", idv, idu, idw); 
            assert(idw != -1);
            if (idu == idw) {
                flag = 1;
            }
            else {
                if (idv < idu) {
                    ans = max(calc(0, idw, v), calc(idw + 1, path.size() - 1, u));
                }
                else {
                    ans = max(calc(0, idw - 1, u), calc(idw, path.size() - 1, v));
                }
            }
        }
        else 
            flag = 1;
        //cerr << "flag: " << flag << endl;
        if (flag) {
            if (distToPath[v] > distToPath[u]) swap(v, u);
            id = idOnPath[goToRoad[v]];
            //epr("id %d\n", id);
            ans = max((int)path.size() - 1 - id, id) + distToPath[v];
        }
        solveAns.pb(ans);
    }
    return solveAns;
}

void read() {
    int v, u;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &v, &u);
        edges.pb(mp(v, u));
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v, &u);
        query.pb(mp(v, u));
    }
}

void genTest() {
    int v, u;
    n = 10000;
    edges.clear();
    for (int i = 2; i <= n; i++)
        edges.pb(mp(i, rand() % (i - 1) + 1));
    m = 1;
    query.clear();
    for (int i = 0; i < m; i++) {
        v = rand() % n;
        u = rand() % (n - 1);
        if (v == u)
            u++;
        v++;    u++;
        query.pb(mp(v, u));
    }
}

int distS[maxn][2];
bool useS[maxn][2];
vector < vector < int > > e1;

void dfsSt(int v, int h, int id) {
    useS[v][id] = 1;
    distS[v][id] = h;
    for (int i = 0; i < (int)e1[v].size(); i++)
        if (!useS[e1[v][i]][id]) {
            dfsSt(e1[v][i], h + 1, id);
        }
}

void printTest() {
    epr("Test\n");
    epr("%d\n", n);
    for (int i = 0; i < n - 1; i++)
        epr("%d %d\n", edges[i].fr, edges[i].sc);
    epr("%d\n", m);
    for (int i = 0; i < m; i++)
        epr("%d %d\n", query[i].fr, query[i].sc);
}

vector < int > stupid() {
    int v, u;
    e1.resize(n);
    for (int i = 0; i < n; i++)
        e1[i].clear();
    for (int i = 0; i < n - 1; i++) {
        e1[edges[i].fr - 1].pb(edges[i].sc - 1);
        e1[edges[i].sc - 1].pb(edges[i].fr - 1);
    }
    /*cerr << "sdfsdf\n";
    for (int i = 0; i < n; i++, cerr << endl) 
        for (int j = 0; j < (int)e1[i].size(); j++)
            epr("%d ", e1[i][j]);*/;
    vector < int > answer;
    for (int i = 0; i < m; i++) {
        v = query[i].fr - 1;
        u = query[i].sc - 1;
        for (int i = 0; i < n; i++)
            useS[i][0] = useS[i][1] = 0;
        dfsSt(v, 0, 0);
        dfsSt(u, 0, 1);
        int ans = 0;
        /*cerr << "dist: \n";
        for (int j = 0; j < 2; j++, cerr << endl)
            for (int i = 0; i < n; i++)
                epr("%d ", distS[i][j]);*/
        for (int i = 0; i < n; i++)
            ans = max(ans, min(distS[i][0], distS[i][1]));
        answer.pb(ans);
    }
    return answer;
}

void stress() {
    for (int t = 0; t < 20000; t++) {
        cerr << "test id: " << t << endl;
        genTest();
        vector < int > r1 = solve();
        vector < int > r2 = stupid();
        bool flag = 1;
        assert(r1.size() == r2.size());
        for (int i = 0; i < (int)r1.size(); i++)
            if (r1[i] != r2[i]) 
                flag = 0;
        if (!flag) {
            cerr << "answer\n";
            cerr << "r1: ";
            for (int i = 0; i < (int)r1.size(); i++)
                epr("%d ", r1[i]);
            cerr << endl;
            cerr << "r2: ";
            for (int i = 0; i < (int)r2.size(); i++)
                epr("%d ", r2[i]);
            cerr << endl;
            printTest();
            return;
        }
    }
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    if (0)
        stress();
    else {
        read();
        vector < int > tmp = solve();
        //vector < int > tmp = stupid();
        for (int i = 0; i < (int)tmp.size(); i++)
            printf("%d\n", tmp[i]); 
    }
    return 0;
}