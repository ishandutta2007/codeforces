#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

const int N = 1e5 + 10;
const int INF = 1e9 + 19;

struct Edge {
    int v, u, c, t;
    Edge() { }
    Edge(int v, int u, int c, int t): v(v), u(u), c(c), t(t) { }
    void read() {
        scanf("%d%d%d%d", &v, &u, &c, &t);
        v--; u--;
    }
};

int n, m;
Edge edge[N];
map < int, int > cntColor[N];
int fire[N];
vector < pair < int, int > > g[N];
vector < pair < int, int > > e[N];
vector < pair < int, int > > h[N];
vector < int > path;
bool use[N];
int p[N];
bool inm[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        edge[i].read();
    }
}

int dfs1(int v) {
    use[v] = 1;
    for (auto x: e[v]) {
        int u = x.fr;
        if (p[u] == -1 || (!use[p[u]] && dfs1(p[u]))) {
            inm[v] = 1;
            p[u] = v;
            return 1;
        }
    }
    return 0;
}

void dfs0(int v) {
    use[v] = 1;
    path.pb(v);
    for (auto x: g[v])
        if (!use[x.fr])
            dfs0(x.fr);
}

vector < int > answer;
vector < int > use2;

void addEdges(vector < int > & path, bool safeMod = 0) {
    if (!safeMod) {
        for (auto v: path) {
            use2[v] = 1;
        }
    }

    for (int j = 0; j < (int)path.size(); j += 2) {
        int v = path[j];
        int u = path[j + 1];
        int id = -1;
        for (auto x: h[v])
            if (x.fr == u)
                id = x.sc;
        answer.pb(id);
    }

}

bool check(vector < int > & answer) {
    vector < int > get(m);
    for (auto x: answer)
        get[x] = 1;
    vector < map < int, int > > cc(n);
    for (int i = 0; i < m; i++) {
        if (!get[i]) {
            cc[edge[i].v][edge[i].c]++;
            cc[edge[i].u][edge[i].c]++;
        }
    }
    for (int i = 0; i < n; i++)
        for (auto x: cc[i])
            if (x.sc > 1)
                return 0;
    return 1;
}

bool can(int mxCost) {
    for (int i = 0; i < n; i++) {
        g[i].clear();
        h[i].clear();
    }
    for (int i = 0; i < m; i++)
        if (edge[i].t <= mxCost) {
            int v = edge[i].v;
            int u = edge[i].u;
            if (fire[v] == fire[u] && edge[i].c == fire[v]) {
                g[v].pb(mp(u, i));
                g[u].pb(mp(v, i));
            }
            if (fire[v] == edge[i].c || fire[u] == edge[i].c) {
                h[v].pb(mp(u, i));
                h[u].pb(mp(v, i));
            }
        }

    for (int i = 0; i < n; i++)
        use[i] = 0; 
    
    vector < vector < int > > hotPath;
    use2.assign(n, 0);
    answer.clear();
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1 && !use[i]) {
            path.clear();
            dfs0(i);
            if (path.size() % 2 == 0) {
                addEdges(path);
            }
            else {
                for (auto x: path) 
                    use2[x] = 1;
                hotPath.pb(path);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!use[i] && g[i].size() == 2) {
            path.clear();
            dfs0(i);
            if (path.size() % 2 == 1) return 0;
            addEdges(path);
        }
    }
       
    for (int i = 0; i < m; i++)  {
        int v = edge[i].v;
        int u = edge[i].u;
        if (fire[v] == -1) swap(v, u);
        if (fire[v] != -1 && fire[u] == -1 && !use2[v] && edge[i].t <= mxCost && edge[i].c == fire[v]) {
            e[v].pb(mp(u, i));
        }
    }
    int cur = n;
    for (auto & path: hotPath) {
        vector < int > other;
        int sz = path.size();
        for (auto x: h[path[0]])
            if (x.fr != path[1])
                other.pb(x.fr);
        for (auto x: h[path[sz - 1]])
            if (x.fr != path[sz - 2])
                other.pb(x.fr);
        for (auto x: other) {
            if (fire[x] == -1)
                e[cur].pb(mp(x, -1));  
        }
        fire[cur] = -2;

        cur++;
    }
    bool flag = 1;
    for (int i = 0; i < cur; i++)
        p[i] = -1;
    for (int i = 0; i < cur; i++)
        inm[i] = 0;

    for (;flag;) {
        flag = 0;
        for (int i = 0; i < cur; i++)
            use[i] = 0;
        for (int i = 0; i < cur; i++)
            if (fire[i] != -1 && use[i] == 0 && !inm[i])  {
                flag |= dfs1(i);    
            }
    }
    
    for (int i = 0; i < cur; i++)
        if (fire[i] == -1 && p[i] != -1) {
            int v = p[i];
            int id = -2;
            for (auto x: e[v])
                if (x.fr == i)
                   id = x.sc; 
            if (id == -1) {
                bool head = 0;
                bool tail = 0;
                auto & path = hotPath[v - n];
                for (auto x: h[path[0]])
                    head |= x.fr == i;
                for (auto x: h[path.back()])
                    tail |= x.fr == i;
                if (tail)
                    path.pb(i);
                else
                    path.insert(path.begin(), i);
                addEdges(path, 1);
            } 
            else 
                answer.pb(id);
        }
    for (int i = 0; i < cur; i++)
        e[i].clear();

    return check(answer);
}

int solve() {
    for (int i = 0; i < n; i++) {
        use[i] = 0;
        cntColor[i].clear();
    }
    vector < int > cc; 
    for (int i = 0; i < m; i++)
        cc.pb(edge[i].t);
    sort(all(cc));
    cc.resize(unique(all(cc)) - cc.begin());

    for (int i = 0; i < m; i++) {

        cntColor[edge[i].v][edge[i].c]++;
        cntColor[edge[i].u][edge[i].c]++;
    }
    bool fail = 0;
    for (int i = 0; i < n; i++)  {
        fire[i] = -1;
        for (auto x: cntColor[i]) {
            if (x.sc > 1) {
                if (fire[i] != -1 || x.sc > 2) 
                    fail = 1;
                fire[i] = x.fr;
            }
        }
    }
    bool easy = 1;
    for (int i = 0; i < n; i++)
        easy &= fire[i] == -1;

    if (easy) {
        answer.clear();
        return 0;
    }
   
    if (fail || !can(cc.back())) {
        return -1;
    }

    int l = -1; 
    int r = cc.size() - 1;
    for (; r - l > 1; ) {
        if (can(cc[(l + r) / 2]))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    can(cc[r]);
    return cc[r];
}

void printAns(int r) {
    if (r == -1) {
        puts("No");
        return;
    }
    puts("Yes");
    printf("%d %d\n", r, (int)answer.size());
    sort(all(answer));
    for (auto x: answer)
        printf("%d ", x + 1);
    puts("");
}

int main(){
    read();
    printAns(solve());
}