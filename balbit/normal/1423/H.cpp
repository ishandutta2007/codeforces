#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
#define SQ(i) ((i)*(i))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define SZ(i) static_cast<int>(i.size())
#define FOR(i, j, k, in) for (int i=j; i < (k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j; i >= (k) ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REP1(i, j) FOR(i, 1, j+1, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(_a) _a.begin(), _a.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
template<typename T, typename S>
istream &operator >> (istream &is, pair<T, S> &p) {
    return is >> p.X >> p.Y;
}
#ifdef tmd
#define TIME(i) Timer i(#i)
#define debug(...) do {\
    fprintf(stderr, "%s - %d (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x) {cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x, S &&..._t) {cerr <<_x <<" ,"; _do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s, const pair<_a, _b> &_p) {return _s << "(" << _p.X << "," << _p.Y << ")";}
template<typename It> ostream& _OUTC(ostream &_s, It _ita, It _itb)
{
    _s << "{";
    for (It _it=_ita; _it != _itb; _it++) {
        _s <<(_it == _ita?"":",")<< *_it;
    }
    _s << "}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s, const vector<_a> &_c) {return _OUTC(_s,ALL(_c));}
template<typename _a, size_t _b> ostream &operator << (ostream &_s, const array<_a,_b> &_c) {return _OUTC(_s, ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s, const deque<_a> &_c) {return _OUTC(_s, ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s, const map<_a,_b> &_c) {return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif

int n, Q, k;
vector<int> qtid;

const int MAXN = 500005;

struct LOG {
    int u, v, su, sv;
};
vector<LOG> logs;

int djs[MAXN], sz[MAXN], comp;
int fnd (int x) {
    return djs[x] == x ? x : fnd(djs[x]);
}

void uni (int x, int y) {
    x = fnd(x);
    y = fnd(y);
    logs.push_back({x, y, sz[x], sz[y]});
    if (x == y) {
        return;
    }
    comp--;
    if (sz[x] > sz[y]) {
        swap(x, y);
    }
    djs[x] = y;
    sz[y] += sz[x];
}

void undo () {
    // assert(!logs.empty());
    LOG cur = logs.back();
    logs.pop_back();
    if (cur.u != cur.v) {
        comp++;
    }
    djs[cur.u] = cur.u;
    sz[cur.u] = cur.su;
    djs[cur.v] = cur.v;
    sz[cur.v] = cur.sv;
}

vector<pii> seg[MAXN*4];

void add_query (pii q, int qL, int qR, int v=1, int nL=0, int nR=Q) {
    if (qL >= nR || qR <= nL || qL >= qR) {
        return;
    } else if (qL <= nL && nR <= qR) {
        seg[v].emplace_back(q);
    } else {
        int nM = (nL + nR) >> 1;
        add_query(q, qL, qR, v<<1, nL, nM);
        add_query(q, qL, qR, v<<1|1, nM, nR);
    }
}


vector<pii> qq[MAXN];
vector<int> ans;
void time_dfs (int v, int l, int r) {
    for (auto p : seg[v]) {
        uni(p.first, p.second);
    }
    if (l >= r - 1) {
        for (auto pp : qq[l]) {
            debug(pp, l);
            pary(djs+1, djs+1+n);
            ans[pp.Y] = sz[fnd(pp.X)];
        }
    } else {
        int m = (l + r) >> 1;
        time_dfs(v<<1, l, m);
        time_dfs(v<<1|1, m, r);
    }

    REP (i, SZ(seg[v])) {
        undo();
    }
}


/*********************GoodLuck***********************/
int main () {
    IOS();

    cin >> n >> Q >> k;

    comp = n;
    REP1 (i, n) {
        djs[i] = i;
        sz[i] = 1;
    }

    int ct = 0;

    vector<int> st;

    vector<pair<pii,pii> > ne;
    st.eb(0);
    for (int i=0; i<Q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x, y;
            cin >> x >> y;
            if (x>y) swap(x,y);
            ne.eb(pii(i,ct+k), pii(x,y));
        } else if (cmd == 2) {
            int x;
            cin >> x;
            qq[i].eb(x, SZ(ans));
            ans.eb(0);
        } else {
            ct++;
            st.eb(i);
        }
    }

    st.eb(Q);
    debug(st);

    map<pii, int> lst;
    for (auto ds : ne) {
        ds.X.Y = min(ds.X.Y, SZ(st)-1);
        pii rng = {ds.X.X, st[ds.X.Y]};
        if (lst.count(ds.Y)) {
            rng.X = max(rng.X, lst[ds.Y]);
        }
        lst[ds.Y] = rng.Y;
        debug(ds.Y, rng);
        add_query(ds.Y, rng.X, rng.Y);
    }

    time_dfs(1, 0, Q);
    for (auto v : ans) cout << v << endl;
    return 0;
}