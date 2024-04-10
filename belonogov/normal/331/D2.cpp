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

using namespace std;

#define F first
#define S second
#define mp make_pair
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
#define next nexttt
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int LOG = 14;
const int BASE = 10;

struct pt {
    int x, y;
    pt () { }
    pt (int xx, int yy): x(xx), y(yy) { }
    void read() {
        scanf("%d%d", &x, &y);
    }
    pt operator + (const pt & A) const {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (const pt & A) const {
        return pt(x - A.x, y - A.y);
    }
    int operator % (const pt & A) const {
        return x * A.x + y * A.y;
    }
    int operator * (const pt & A) const {
        return x * A.y - y * A.x;
    }
    bool operator == (const pt & A) const {
        return x == A.x && y == A.y;
    }
    ll len() {
        return abs(x) + abs(y);
    }
    pt operator * (int k) const {
        return pt(x * k, y * k);
    }
};

const pt dir[4] = {pt(1, 0), pt(0, 1), pt(-1, 0), pt(0, -1)};

struct Query {
    pt p;
    int dirId;
    ll tmr;
};

struct Tree {
    vector<int> data;
    void init(int n) {
        data.assign(n * 4, -1);
    }
    /// -1 boarder
    /// -2 null
    void push(int v) {
        if (data[v] != -2) {
            data[v * 2 + 1] = data[v];
            data[v * 2 + 2] = data[v];
            data[v] = -2;
        }
    }

    void add(int v, int tl, int tr, int l, int r, int val) {
        if (tr <= l || r <= tl) return;
        if (l <= tl && tr <= r) {
            data[v] = val;
            return;
        }
        push(v);
        add(v * 2 + 1, tl, (tl + tr) / 2, l, r, val);
        add(v * 2 + 2, (tl + tr) / 2, tr, l, r, val);
    }
    int get(int v, int tl, int tr, int pos) {
        //assert(tl <= pos && pos < tr);
        if (data[v] != -2) {
            return data[v];
        }  
        if (pos < (tl + tr) / 2)
            return get(v * 2 + 1, tl, (tl + tr) / 2, pos);
        else
            return get(v * 2 + 2, (tl + tr) / 2, tr, pos);
    }
};

struct Event {
    int t, type, id, l, r;
    Event() { }
    Event(int _t, int _type, int _id, int _l, int _r): t(_t), type(_type), id(_id), l(_l), r(_r) { }
    void Epr() {
        cerr << "t type id l r: " << t << " " << type << " "  << id << " " << l << " " << r << endl;
    }
};

struct State {
    pt A;
    pt v;
    int nextId;
    ll len;
    State() { }
    State(pt _A, pt _v, int _nextId, ll _len): A(_A), v(_v), nextId(_nextId), len(_len) { }
};

pt getDir(pt A, pt B) {
    pt v = B - A;
    int len = abs(v.x) + abs(v.y);
    v.x /= len;
    v.y /= len;
    return v;
}

int n, b, q;
pair<pt,pt> p[N];
pt segDir[N];
Query query[N];
int next[N * 2];
State go[N][LOG];
ll deg[LOG];

void read() {
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; i++) {
        p[i].F.read();
        p[i].S.read();
    }
    scanf("%d", &q);
    //db3(n, b, q);
    for (int i = 0; i < q; i++) {
        char ch;
        scanf("%d%d %c%lld", &query[i].p.x, &query[i].p.y, &ch, &query[i].tmr);
        if (ch == 'R') query[i].dirId = 0;
        if (ch == 'U') query[i].dirId = 1;
        if (ch == 'L') query[i].dirId = 2;
        if (ch == 'D') query[i].dirId = 3;
    }
}

ll distToSeg(int segId, pt C) {
    pt v = segDir[segId]; 
    if ((C - p[segId].F) % v >= 0 && (C - p[segId].S) % v <= 0) {
        return abs(v * (C - p[segId].F));
    }
    //assert(v * (C - A) == 0);
    return min((C - p[segId].F).len(), (C - p[segId].S).len());
}

int cc;
State eval(State st, int bound) {
    int i = bound;
    for (;; ) {
        //db(i);
        cc++;
        int rId = st.nextId;
        //db(rId);
        if (rId == -1) {
            ll mxDist = -1;
            if (st.v == dir[0]) mxDist = b - st.A.x;
            if (st.v == dir[1]) mxDist = b - st.A.y;
            if (st.v == dir[2]) mxDist = st.A.x;
            if (st.v == dir[3]) mxDist = st.A.y;
            ll d = min(mxDist, st.len);
            st.A = st.A + st.v * d;
            st.len -= d;
            return st;
        }
        //db("tmp");
        ll d = min(st.len, distToSeg(rId, st.A));
        st.len -= d;        
        st.A = st.A + st.v * d;
        if (st.len == 0) break;

        //db("2tmp");
        d = min(st.len, (p[rId].S - st.A).len());
        st.len -= d;
        st.A = st.A + segDir[rId] * d;
        if (st.len == 0) break;
        //db("xxx");

        //assert(st.A == p[rId].S);
        //db(st.len);
        for (; st.len < deg[i]; i--);
            //db(i);
        //db(i);
        if (st.len >= deg[i]) {
            ll oldLen = st.len;
            st = go[rId][i];
            st.len = oldLen - deg[i];
        } 
    }
    ///assert(st.len == 0);
    return st;
}

bool cmp(Event A, Event B) {
    return A.t > B.t || (A.t == B.t && A.type < B.type);
}



void solve() {
    deg[0] = 1;
    for (int i = 1; i < LOG; i++)
        deg[i] = deg[i - 1] * BASE;

    for (int i = 0; i < n; i++)
        segDir[i] = getDir(p[i].F, p[i].S);

    for (int t = 0; t < 4; t++) {
        //db(t);
        vector<Event> event;
        pt v = dir[t];
        for (int i = 0; i < n; i++) {
            int tmr = max(v % p[i].F, v % p[i].S); 
            int l = min(v * p[i].F, v * p[i].S);
            int r = max(v * p[i].F, v * p[i].S);
            event.pb(Event(tmr, 0, i, l, r));
        }

        for (int i = 0; i < n; i++) {
            pt u = segDir[i];
                //getDir(p[i].F, p[i].S);
            if (u == v) {
                pt A = p[i].S + u;
                event.pb(Event(A % v, 1, i, v * A, v * A));
            }
        }
        for (int i = 0; i < q; i++) {
            if (dir[query[i].dirId] == v) {
                event.pb(Event(query[i].p % v, 1, i + n, v * query[i].p, v * query[i].p));           
            }
        }

        //for (auto ee: event) {
            //ee.Epr();
        //}

        int mnT = 0; 
        int mnY = 0;
        for (int i = 0; i < (int)event.size(); i++) {
            Event ee = event[i];
        //for (auto ee: event) {
            mnT = min(mnT, ee.t);
            mnY = min(mnY, ee.l);
            //assert(ee.l <= ee.r);
        }
        //for (auto& ee: event) {
        for (int i = 0; i < (int)event.size(); i++) {
            event[i].t -= mnT;
            event[i].l -= mnY;
            event[i].r -= mnY;
            //assert(ee.r <= b);
        }

        sort(all(event), cmp);

        Tree tree;
        tree.init(b + 1);
        //for (auto ee: event) {
        for (int i = 0; i < (int)event.size(); i++) {
            Event ee = event[i];
            if (ee.type == 0) {
                tree.add(0, 0, b + 1, ee.l, ee.r + 1, ee.id); 
            }                
            else {
                next[ee.id] = tree.get(0, 0, b + 1, ee.l);
            }
        }
    }
    //db("fin");
    //cerr << "next: ";
    //for (int i = 0; i < n + q; i++)
        //cerr << next[i] << " ";
    //cerr << endl;

    //pt A;
    //pt v;
    //int nextId;
    //ll len;
    //cerr << "0 " << clock() * 1.0 / CLOCKS_PER_SEC << endl;

    for (int i = 0; i < n; i++) {
        pt v = segDir[i];
            //getDir(p[i].F, p[i].S);
        go[i][0] = State(p[i].S + v, v, next[i], 0);
    }
    cerr << "1 " << clock() * 1.0 / CLOCKS_PER_SEC << endl;

    //ll sum = 0;
    //ll cnt = 0;
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            State st(p[i].S, segDir[i], next[i], deg[j]);
            cc = 0;
            go[i][j] = eval(st, j - 1);
            //assert(cc < LOG);
            //sum += cc;
            //cnt++;
        }
    }
    ///db2("avg: ", sum * 1.0 / cnt);
    //cerr << "go Done" << endl;
    cerr << "2 " << clock() * 1.0 / CLOCKS_PER_SEC << endl;

    for (int i = 0; i < q; i++) {
        //db(i);
        State st(query[i].p, dir[query[i].dirId], next[i + n], query[i].tmr);
        State res = eval(st, LOG - 1);
        printf("%d %d\n", res.A.x, res.A.y);
    }
    //db("fff");

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("test.txt", "r", stdin);
    freopen("out", "w", stdout);
    //freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
        cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    }
    else {
        stress();
    }

    return 0;
}