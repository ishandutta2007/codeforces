#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

vector<int, int> &
getVector(const unordered_map<ll, int> &trad, vector<map<int, int>> &g, int dst, int &prox, ll res, int v, int i);

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007
#define PI acos(-1.0)

/*
bool sacar(pll izq, pll p, pll der){
    ll x1 = izq.first; ll y1 = izq.second;
    ll x2 = p.first; ll y2 = p.second;
    ll x3 = der.first; ll y3 = der.second;
    ll ym = y1 * (x3 - x2) + y3 * (x2 - x1);
    y2 *= (x3 - x1);
    return y2 <= ym;
}

bool sacarIzq(set<pll>& ch, pll p){
    auto it = ch.find(p);
    if(it != ch.begin()){
        auto itizq = it;
        itizq--;
        if(itizq != ch.begin()){
            auto itizqizq = itizq;
            itizqizq--;
            if(sacar(*itizqizq,*itizq,*it)) {
                ch.erase(itizq);
                return true;
            }
        }
    }
    return false;
}

bool sacarDer(set<pll>& ch, pll p){
    auto it = ch.find(p);
    auto itder = it;
    itder++;
    if(itder != ch.end()){
        auto itderder = itder;
        itderder++;
        if(itderder != ch.end() and sacar(*it,*itder,*itderder)){
            ch.erase(itder);
            return true;
        }
    }
    return false;
}

void meter(set<pll>& ch, pll p){
    auto it = ch.lower_bound(mp(p.first,-INF));
    if(it != ch.end() and it->first == p.first and it->second >= p.second) return;
    else ch.insert(p);
    auto itizq = ch.find(p);
    if(itizq != ch.begin()){
        itizq--;
        auto itder = ch.find(p);
        itder++;
        if(itder != ch.end() and sacar(*itizq,p,*itder)){
            ch.erase(p);
            return;
        }
    }

    while(sacarIzq(ch,p));
    while(sacarDer(ch,p));
}

vector<int> p, l, h, x, y;
vll res;
const int N = 1000005;
int donde[N];

vector<int> read(int n, int k, int m){
    vector<int> v(n);
    for(int i = 0; i < k; ++i) {
        cin>>v[i];
    }
    int A, B, C;
    cin>>A>>B>>C;
    if(m == -2) {
        cin>>m;
    }
    for(int i = k; i < n; ++i) {
        v[i] = ((ll) A * v[i-2] + (ll) B * v[i-1] + C) % (m == -1 ? i : m) + 1;
    }
    return v;
}

void mergear(vector<set<pll>>& ch, int aa, int bb){
    int a = donde[aa];
    int b = donde[bb];
    if(a == b) return;
    if(ch[a].size() < ch[b].size()) {
        donde[aa] = donde[bb];
        swap(a,b);
    }
    else donde[bb] = donde[aa];
    for(auto p : ch[b]) meter(ch[a],p);
}

ll costo(ll h, pll p) {
    return p.first*h - p.second;
}

ll queryAns(set<pll>& ch, ll h, ll d){
    if(ch.empty())
        return 0;
    ll lo = 0; //res in [lo,hi)
    ll hi = 2e12;
    while(lo+1 != hi){
        ll m = (lo+hi)/2;
        auto it2 = ch.lower_bound(mp(m-1,1));
        auto it1 = it2;
        if(it1 != ch.begin()) it1--;
        if(it2 == ch.begin() or (it2 != ch.end() and costo(h,*it1) > costo(h,*it2))) lo = m;
        else hi = m;
    }
    auto it = ch.lower_bound(mp(lo-1,1));
    ll res = costo(h,*it);
    res -= h*d;
    return res;
}

vvi hijos;
vector<set<pll>> ch;
vvll querys;

void dfs(int nodo, ll d){
    donde[nodo] = nodo;
    F0(i,hijos[nodo].size()) {
        d += l[hijos[nodo][i]];
        dfs(hijos[nodo][i],d);
        d -= l[hijos[nodo][i]];
        mergear(ch,nodo,hijos[nodo][i]);
    }
    meter(ch[donde[nodo]],mp(d,-queryAns(ch[donde[nodo]],h[nodo],d)));

    F0(i,querys[nodo].size()) {
        res.pb(queryAns(ch[donde[nodo]],querys[nodo][i],d) % mod +1);
    }
}

void d(int tc){
    res.clear();
    int n, m, k;
    cin>>n>>m>>k;
    p = read(n, k, -1);
    l = read(n, k, -2);
    h = read(n, k, -2);
    x = read(m, k, n);
    y = read(m, k, -2);

    hijos = vvi(n);
    for(int i = 0; i < (int) p.size(); ++i) {
        --p[i]; // 0 becomes -1 !!!
        if(i > 0) hijos[p[i]].push_back(i);
    }

    querys = vvll(n);
    F0(i,x.size()){
        x[i]--;
        querys[x[i]].emplace_back(y[i]);
    }

    ch = vector<set<pll>>(n);
    dfs(0,0);

    vll debug = res;
    F1(i,res.size()-1) res[i] = (res[i] * res[i-1]) % mod;
    cout<<"Case #"<<tc<<": "<<res.back()<<'\n';
}
*/

struct persistentDSU{
    persistentDSU(int n){
        p.resize(n);
        F0(i,n) p[i] = i;
        s = vi(n,1);
        stack = {{}};
        comp = n;
    }

    int find(int u){
        while(u != p[u]) u = p[u];
        return u;
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        comp--;
        if(s[u] < s[v]) swap(u,v);
        stack.back().eb(mp(u,v));
        p[v] = u;
        s[u] += s[v];
    }

    void persist(){
        vpi v;
        stack.eb(v);
    }

    void rollback(){
        comp += stack.back().size();
        while(!stack.back().empty()){
            int u = stack.back().back().first;
            int v = stack.back().back().second;
            p[v] = v;
            s[u] -= s[v];
            stack.back().pop_back();
        }
        stack.pop_back();
    }

    vi p;
    vi s;
    vvpi stack;
    int comp;
};

struct Query{
    Query(int type, int u, int v, int l, int r) : type(type), u(u), v(v), l(l), r(r) {}

    int type;
    int u;
    int v;
    int l;
    int r;
};

bool intersects(int l1, int r1, int l2, int r2){
    return max(l1,l2) < min(r1,r2);
}

void solve(int l, int r, vector<Query>& queries, persistentDSU& uf){
    uf.persist();
    if(l+1 == r){
        for(auto q : queries){
            if(q.type == 2 and q.l <= l and q.r >= r) uf.unite(q.u,q.v);
        }
        for(auto q : queries){
            if(q.type == 1 and q.l == l) cout<<uf.s[uf.find(q.v)]<<'\n';
        }
        uf.rollback();
        return;
    }
    vector<Query> queries2;
    for(auto q : queries){
        if(q.type == 2 and l >= q.l and r <= q.r){
            uf.unite(q.u,q.v);
            continue;
        }
        if(q.type == 1 and l <= q.l and q.l < r)
            queries2.pb(q);
        if(q.type == 2 and intersects(l,r,q.l,q.r))
            queries2.pb(q);
    }
    int m = (l+r)/2;
    solve(l,m,queries2,uf);
    solve(m,r,queries2,uf);
    uf.rollback();
}

struct coso{
    char op;
    int u;
    int v;

    coso(char op, int u, int v) : op(op), u(u), v(v) {}
};

void dinamic(vector<coso>& ev, int n, int m){
    if(m == 0)
        return;
    persistentDSU uf(n);
    map<pi,int> tmas;
    vector<Query> queries;
    char op;
    int u,v;
    int t = 0;

    F0(i,m){
        op = ev[i].op;
        if(op == '+'){
            tie(u,v) = {ev[i].u,ev[i].v};
            if(u > v) swap(u,v);
            tmas[{u,v}] = t;
        }
        if(op == '-'){
            tie(u,v) = {ev[i].u,ev[i].v};
            if(u > v) swap(u,v);
            queries.eb(Query(2,u,v,tmas[{u,v}],t));
            tmas.erase({u,v});
        }
        if(op == '?'){
            v = ev[i].v;
            queries.eb(Query(1,0,v,t,0));
            t++;
        }
    }
    for(auto coso : tmas){
        u = coso.first.first;
        v = coso.first.second;
        int l = coso.second;
        queries.eb(Query(2,u,v,l,t));
    }
    solve(0,t,queries,uf);
}

void h(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<coso> c;
    int type,u,v;
    vector<set<pi>> reg(1);
    map<pi,int> ult;
    int t = 0;
    F0(i,m){
        cin>>type;
        if(type == 1){
            cin>>u>>v;
            u--; v--;
            if(u > v) swap(u,v);
            if(ult.count({u,v}) and ult[{u,v}]+k > t) {
                reg[ult[{u,v}]].erase({u,v});
                ult[{u,v}] = t;
                reg[t].insert({u,v});
            }
            else {
                c.pb(coso('+',u,v));
                ult[{u,v}] = t;
                reg[t].insert({u,v});
            }
        }
        if(type == 2){
            cin>>v;
            v--;
            c.pb(coso('?',v,v));
        }
        if(type == 3){
            reg.pb(set<pi>());
            t++;
            if(t-k >= 0) for(auto e : reg[t-k]) c.pb(coso('-',e.first,e.second));
        }
    }
    m = c.size();
    dinamic(c,n,m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    h();
    return 0;
}