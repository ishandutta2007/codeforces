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

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
//#define pb push_back
#define eb emplace_back
#define pb push_back
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
*/

unordered_map<ll,ll> ceros;
unordered_map<ll,ll> unos;
ll a[300001];

void c(){
    int n;
    cin>>n;
    F0(i,n) cin>>a[i];
    ll res = 0;
    ll inv = 0;
    F0R(bi,30){
        ll inv0 = 0;
        ll inv1 = 0;
        ceros.clear();
        unos.clear();
        F0(i,n) {
            ll ind = (a[i]>>(bi+1));
            if(a[i] & (1ll<<bi)){
                inv1 += ceros[ind];
                unos[ind]++;
            }
            else {
                inv0 += unos[ind];
                ceros[ind]++;
            }
        }
        if(inv1 < inv0) res += (1ll<<bi);
        inv += min(inv0,inv1);
    }

    cout<<inv<<' '<<res<<'\n';

}

class unionFindPC {
public:
    unionFindPC(int n);
    int find(int i); // pre, el nodo est
    void unite(int s, int t);
private:
    vector<int> set; //en la posicin de cada elemento est su padre
    vector<int> peso; //peso
};

struct mov{
    mov(int desde, int hasta, const vi &coso) : desde(desde), hasta(hasta), coso(coso) {}
    mov(){
        desde = 0;
        hasta = 0;
        coso = {};
    }
    int desde;
    int hasta;
    vi coso;
};

void unir(vi& donde, vi& peso, vvi& alcanzable, int u, int v, vector<mov>& log, int i){
    u = donde[u];
    v = donde[v];
    if(u == v) return;
    if(peso[u] < peso[v]) swap(u,v);
    log[i] = mov(v,u,alcanzable[v]);
    for(auto c : alcanzable[v]) {
        donde[c] = u;
        alcanzable[u].pb(c);
    }
    peso[u] += peso[v];
    peso[v] = 0;
    alcanzable[v].clear();
}

void d(){
    int n,m,q;
    cin>>n>>m>>q;
    vvi alcanzable(n);
    vi p(n);
    F0(i,n) cin>>p[i];
    F0(i,n) alcanzable[i].pb(i);
    vpi aristas(m);
    F0(i,m){
        cin>>aristas[i].first>>aristas[i].second;
        aristas[i].first--; aristas[i].second--;
    }
    vpi query(q);
    vb seElimina(m,false);
    F0(i,q){
        cin>>query[i].first>>query[i].second;
        query[i].second--;
        if(query[i].first == 2) seElimina[query[i].second] = true;
    }
    vi res;
    vi donde(n);
    F0(i,n) donde[i] = i;
    vi peso(n);
    F0(i,n) peso[i] = 1;
    vector<mov> log(m);

    F0(i,m){
        if(!seElimina[i])
            unir(donde,peso,alcanzable,aristas[i].first,aristas[i].second,log,i);
    }

    int t,v,ar;
    F0R(i,q){
        t = query[i].first;
        if(t == 2){
            ar = query[i].second;
            unir(donde,peso,alcanzable,aristas[ar].first,aristas[ar].second,log,ar);
        }
    }

    vector<set<int>> ps(n);
    F0(i,n) ps[donde[i]].insert(p[i]);

    F0(i,q){
        t = query[i].first;
        if(t == 1){
            v = query[i].second;
            v = donde[v];
            if(ps[v].empty()) res.pb(0);
            else {
                res.pb(*(--ps[v].end()));
                ps[v].erase(res.back());
            }
        }
        else {
            ar = query[i].second;
            int origen = log[ar].desde;
            int destino = log[ar].hasta;
            if(origen != destino){
                for(auto c : log[ar].coso){
                    if(ps[destino].count(p[c])) {
                        ps[destino].erase(p[c]);
                        ps[origen].insert(p[c]);
                    }
                    donde[c] = origen;
                }
            }
        }
    }

    F0(i,res.size()) cout<<res[i]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    d();
    return 0;
}