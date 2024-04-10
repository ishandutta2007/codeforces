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

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int f[N];

struct Node {
    int val, len, l, r;
    void Epr() {
        cerr << "val len l r: " << val << " " << len << " " << l << " " << r << endl;
    }
};

Node merge(Node A, Node B) {
    Node res;
    res.len = A.len + B.len;
    res.val = A.val + B.val;
    res.r = (B.r == B.len)? B.len + A.r: B.r;
    res.l = (A.l == A.len)? A.len + B.l: A.l;
    if (A.len != A.l && B.l != B.len) {
        res.val += f[A.r + B.l];
    }   
    return res;
}

struct SegTree {
    vector<Node> data;
    int nn;
    void init(int n) {
        data.clear();
        nn = n;
        data.resize(n * 2, {0, 1, 0, 0});
    }
    void add(int p) {
        p += nn;
        data[p] = {0, 1, 1, 1};
        p /= 2;
        for (; p >= 1; p /= 2)
            data[p] = merge(data[p * 2], data[p * 2 + 1]);
    }
    Node get(int l, int r) {
        l += nn;
        r += nn;
        Node resL = {0, 0, 0, 0};
        Node resR = {0, 0, 0, 0};
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) resL = merge(resL, data[l++]);
            if (r & 1) resR = merge(data[--r], resR);
        } 
        return merge(resL, resR);
    }
};

struct Event {
    int t, type, v, u, id;
};


int par[N];
int root[N];
int pos[N];
int heavy[N];
int h[N];
SegTree tree;
vector<Event> event;
int n, q;

struct Query {
    int v, u, c;
};

vector<Query> query;



vector<pair<int,int>> e[N];

int dfs(int v) {
    int mxSize = 0;
    int sz = 1;
    for (auto x: e[v]) {
        int u = x.F;
        if (u == par[v]) continue;
        par[u] = v;
        h[u] = h[v] + 1;
        event.pb({x.S, 1, u, -1, -1});
        int chSize = dfs(u);
        if (chSize > mxSize) {
            mxSize = chSize;
            heavy[v] = u;
        }
        sz += chSize;
    }
    return sz;
}

Node processPath(int v, int u) {
    //db2(v, u);
    Node resV = {0, 0, 0, 0};
    Node resU = {0, 0, 0, 0};
    //db2(pos[v], pos[u]);
    //db2(pos[root[v]], pos[root[u]]);
    //for (int i = 0; i < n; i++)
        //db2(i, root[i]);
    for (; root[u] != root[v];) {
        if (h[root[u]] < h[root[v]]) {
            resV = merge(tree.get(pos[root[v]], pos[v] + 1), resV); 
            v = par[root[v]];
        }
        else {
            resU = merge(tree.get(pos[root[u]], pos[u] + 1), resU);
            u = par[root[u]];
        }
    }
    //db2(v, u);
    //db2(h[v], h[u]);
    //cerr << "v; ";
    //resV.Epr();
    //cerr << "u: ";
    //resU.Epr();
    if (h[v] > h[u])  {
        resV = merge(tree.get(pos[u] + 1, pos[v] + 1), resV);
        //cerr << "vvvv; "; resV.Epr();
    }
    else
        resU = merge(tree.get(pos[v] + 1, pos[u] + 1), resU);
    swap(resV.l, resV.r);
    //cerr << "vvvv; "; resV.Epr();
    return merge(resV, resU);
}


void read() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w); v--; u--;
        e[v].pb({u, w});
        e[u].pb({v, w});
    }

    query.clear();
    for (int i = 0; i < q; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--;
        query.pb({v, u, c});
        //db3(v, u, c);
        //event.pb({c, 2, v, u, i});
    }
}

vector<int> solve() {
    fill_n(heavy, n, -1);
    event.clear();
    //srand(time(NULL));
    //int rt = rand() % n;
    int rt = 0;
    //db(rt);
    par[rt] = rt;
    h[rt] = 0;
    dfs(rt); 
    int curPos = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == i || heavy[par[i]] != i) {
            int v = i;
            for (;v != -1 ; v = heavy[v]) {
                pos[v] = curPos++;  
                root[v] = i;
            }
        }
    }

    //for (auto x; query) {
    for (int i = 0; i < (int)query.size(); i++) {
        auto x = query[i];
        event.pb({x.c, 2, x.v, x.u, i});
    }



    tree.init(n);
    vector<int> answer(q);

    sort(all(event), [](Event A, Event B) { return A.t > B.t || (A.t == B.t && A.type < B.type); });


    for (auto x: event) {
        if (x.type == 1) {
            tree.add(pos[x.v]);
        }
        else {
            //tree.get(0, curPos).Epr();
            auto res = processPath(x.v, x.u);
            //res.Epr();
            int ans = res.val;
            if (res.l == res.len) {
                ans += f[res.len];
            }
            else {
                ans += f[res.l] + f[res.r];
            }
            answer[x.id] = ans;
        }
    }
    return answer;
}

void printAns(vector<int> answer) {
    for (auto x: answer)
        printf("%d\n", x);
}

void genTest() {
    n = rand() % 10 + 1;    
    //n = 
    for (int i = 1; i < n; i++)
        f[i] = rand() % 5;
    for (int i = 0; i < n; i++)
        e[i].clear();

    for (int i = 1; i < n; i++) {
        int v = rand() % i;
        int w = rand() % 10;
        e[v].pb({i, w});
        e[i].pb({v, w});
    }
    q = 1;
    query.clear();
    for (int i = 0; i < q; i++) {
        int v = rand() % n;
        int u = rand() % n;
        int w = rand() % 10;
        query.pb({v, u, w});
    }
}

vector<int> st;
int slow_ans;
bool use[N];

void dfs_slow(int v, int fin, int w) {
    use[v] = 1;
    if (v == fin) {
        slow_ans = 0;
        for (int i = 0; i < (int)st.size(); ) {
            if (st[i] == 1) {
                int j = i;
                for (; i < (int)st.size() && st[i] == 1; i++);
                slow_ans += f[i - j];
            }
            else {
                i++;
            }
        }
    }
    for (auto x: e[v]) {
        int u = x.F;
        if (!use[u]) {
            st.pb((x.S >= w));
            dfs_slow(u, fin, w);
            st.pop_back();
        }
    }

}

vector<int> slow() {
    st.clear();
    vector<int> answer;
    for (auto x: query) {
        for (int i = 0; i < n; i++)
            use[i] = 0;
        dfs_slow(x.v, x.u, x.c);  
        answer.pb(slow_ans);

    }
    return answer;
}

void printTest() {
    cout << n << " " << q << endl;
    for (int i = 1; i < n; i++)
        cout << f[i] << " ";
    cout << endl;
    for (int v = 0; v < n; v++)
        for (auto x: e[v])
            if (v < x.F) {
                cout << v + 1 << " " << x.F + 1 << " " << x.S << endl;
            }
    for (auto x: query) {
        cout << x.v + 1 << " " << x.u + 1 << " " << x.c << endl;
    }
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        printTest();
        auto r1 = solve();
        auto r2 = slow();
        cerr << "r1: "; for (auto x: r1) cerr << x << " "; cerr << endl;
        cerr << "r2: "; for (auto x: r2) cerr << x << " "; cerr << endl;
        assert(r1 == r2);
    }
}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        read();
        printAns(solve());
        //cerr << endl;
        //printAns(slow());
    }
    else {
        stress();
    }
    #ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}