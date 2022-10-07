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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 5e5 + 10;
const int INF = 1e9;

int n, m;
int h[N];
int s[N];
vector < int > e[N];
vector < int > g[N];
int dist[N];
bool use[N];
vector < int > nodes;
priority_queue < pair < int, int > > q;
int answer = INF;
vector < vector < int > > values;
vector < vector < int > > valuesUp;
int h2[N];
int h3[N];
int res[N];
int cur;
multiset < int, greater < int > > t;

void addE(int v, int u) {
    g[v].pb(u);
    g[u].pb(v);
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        addE(v, u);
        //g[v].pb(u);
        //g[u].pb(v);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &s[i]);
}

void make(int l, int r, vector < int > & back) {
    for (int i = l; i < r; i++) {
        for (int j = 0; j < (int)values[i].size(); j++) {
            auto it = t.lower_bound(values[i][j]);
            if (it == t.end())
                break;
            back.pb(*it);
            t.erase(it);
        }    
    } 
}

void ret(vector < int > & back) {
    for (int i = 0; i < (int)back.size(); i++)
        t.insert(back[i]);
        //t.set(0, 0, t.sz, back[i], s[back[i] + cur]);
}

void go(int v) {
    //db(res[0]);
    //db(res[1]);
    vector < int > back;
    //cerr << "go v: " << v << endl;
    //cerr << "add\n"; 
    for (int i = 0; i < (int)valuesUp[v].size(); i++) {
        //db(valuesUp[v][i]);
        //cerr << "add\n"; 
        auto it = t.lower_bound(valuesUp[v][i]);
        if (it == t.end())
            break;
        back.pb(*it);
        t.erase(it);
        //int tmp = t.getAndSet(0, 0, t.sz, valuesUp[v][i]);
        //db(tmp);


        //if (tmp == -1)
            //break;
        //back.pb(tmp);
    } 
    //db(t.data[0]);
    if (t.empty())
        answer = min(answer, res[v]);
    ret(back);
}

void f(int l, int r) {
    //cerr << "l r: " << l << " " << r << endl;
    //db(t.sz);
    if (l == r) assert(false);
    if (l + 1 == r) {
        go(l);
        return;
    }
    vector < int > back;
    make((l + r) / 2, r, back);
    f(l, (l + r) / 2);
    ret(back);
    //db(answer);

    back.clear();
    make(l, (l + r) / 2, back);
    f((l + r) / 2, r);
    ret(back);
}

void dfs0(int v, int hh) {
    hh = min(hh, h[v]);
    h2[v] = hh;
    use[v] = 1;
    for (auto u: g[v]) {
        if (!use[u]) {
            e[v].pb(u);
            dfs0(u, hh);
        }
    }
}

void dfs1(int v, int id) {
    values[id].pb(h2[v]);
    for (auto u: e[v])
        dfs1(u, id);
}

void dfs3(int v, int flag, int id, int hh) {
    if (flag == -1) 
        hh = min(h[v], hh);
    h3[v] = hh;
    valuesUp[id].pb(h3[v]);
    for (auto u: e[v])
        dfs3(u, -1, id, hh);
}

void solve() {
    memset(use, 0, sizeof(use));
    dfs0(0, INF);
    sort(s, s + m, greater < int >());

    dist[0] = h[0];
    q.push(mp(h[0], 0));
    cur = 0;


    //cerr << m << endl;
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    //int ccc = 0;
    while (!q.empty() && cur < m) {
        //ccc++;
        pair < int, int > pr = q.top();
        if (pr.fr < s[cur]) break;
        int v = pr.sc;
        //cerr << "v: " << v << endl;
        q.pop();
        for (auto u: e[v]) {
            //cerr << " d h: " << v << "->" << u << "    " << dist[v] << " " << h[u] << endl;
            dist[u] = min(dist[v], h[u]);
            //cerr << "add dist[u]: " << dist[u] << endl;
            q.push(mp(dist[u], u));
        }
        cur++; 
    }
    //db(ccc);
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    //cerr << "cur: " << cur << endl;
    if (cur == m) {
        printf("0\n");
        return;
    }
    int needH = s[cur]; 
    //t.init(m - cur, s + cur);
    for (int i = cur; i < m; i++)
        t.insert(s[i]);

    for (;!q.empty();) {
        nodes.pb(q.top().sc);
        q.pop();
    }
    //cerr << "nodes sz; " << nodes.size() << endl;

    for (int i = 0; i < (int)nodes.size(); i++) {
        res[i] = needH - dist[nodes[i]];
        assert(res[i] > 0);
    }
    //cerr << "1\n";

    values.resize(nodes.size());
    for (int i = 0; i < (int)nodes.size(); i++) {
        dfs1(nodes[i], i);
        sort(values[i].begin(), values[i].end(), greater < int > ());
    }
    //cerr << "1\n";
    
    valuesUp.resize(nodes.size());
    for (int i = 0; i < (int)nodes.size(); i++) {
        dfs3(nodes[i], 1, i, needH);
        sort(valuesUp[i].begin(), valuesUp[i].end(), greater < int > ());
    }

    //cerr << "valuesUp:\n";
    //for (auto x: valuesUp) {
        //for (auto y: x)
            //cerr << y << " " ;
        //cerr << endl;
    //}


    f(0, nodes.size()); 
    if (answer == INF)
        printf("-1\n");
    else
        printf("%d\n", answer);
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

}

void printAns() {

}

void stress() {
    for (int t = 0; t < 1; t++) {
        cerr << "test id: " << t << endl;
        n = 500000;
        for (int i = 0; i < n; i++)
            h[i] = 1;
        h[0] = 100;
        for (int i = 0; i < n - 1; i++) {
            addE(0, i + 1);
        }
        m = n;
        for (int i = 0; i < m; i++)
            s[i] = 2;
        solve();
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}