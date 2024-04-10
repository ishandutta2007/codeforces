#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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

typedef unsigned int uint;

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

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    int i = 0;
    int res = 0;
    while(i < n){
        int j = i+1;
        while(j < n and a[j] == a[j-1]+1) j++;
        maxi(res,j-i-2);
        i = j;
    }
    if(a[0] == 1){
        int i = 1;
        while(i < n and a[i] == a[i-1]+1) i++;
        maxi(res,i-1);
    }
    if(a.back() == 1000){
        int i = n-2;
        while(i >= 0 and a[i] == a[i+1]-1) i--;
        maxi(res,n-2-i);
    }
    cout<<res<<'\n';
}

map<ll,int> factorizar(ll n){
    map<ll,int> res;
    ll d = 2;
    while(d*d <= n){
        while(n%d == 0){
            res[d]++;
            n /= d;
        }
        d++;
    }
    if(n > 1) res[n]++;
    return res;
}

bool casoEspecial(map<ll,int> f){
    int a = f.begin()->second;
    forall(it,f) if(it->second != a) return false;
    forall(it,f){
        while(it->second % 2 == 0) it->second/=2;
        if(it->second != 1) return false;
    }
    return true;
}

void b(){
    ll n;
    cin>>n;
    map<ll,int> f = factorizar(n);
    int maxF = 0;
    forall(it,f) maxi(maxF,it->second);
    ll res = 1;
    forall(it,f) res *= it->first;
    int res2 = 0;
    while(maxF > 1){
        maxF = (maxF+1)/2;
        res2++;
    }
    if(!casoEspecial(f)) res2++;
    cout<<res<<' '<<res2<<'\n';
}

const int N = 200000;
ll pot2[N];

void c(){
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    char c;
    F1(i,n){
        cin>>c;
        if(c == '1') a[i] = 1;
        a[i] += a[i-1];
    }
    pot2[0] = 1;
    F1(i,N-1) pot2[i] = (pot2[i-1]*2) % mod;

    int l,r,unos,ceros;
    ll res;
    while(q--){
        cin>>l>>r;
        unos = a[r] - a[l-1];
        ceros = r-l+1 - unos;
        res = pot2[unos]-1;
        res += (pot2[unos] * (pot2[ceros]-1))%mod;
        res -= pot2[ceros] - 1;
        res %= mod;
        res += mod;
        res %= mod;
        cout<<res<<'\n';
    }
}

void d(){
    ll n;
    cin>>n;
    ll x = 2;
    ll res = 0;
    while(x < n){
        ll a = 2;
        while(a*x <= n){
            res += 4*x;
            a++;
        }
        x++;
    }
    cout<<res<<'\n';
}

struct nodo{
    nodo(){
        v = INF;
    }

    void combinar(nodo a, nodo b){
        v = min(a.v,b.v);
    }

    ll v;
};

struct segmentTree{
    segmentTree(vi& values);
    segmentTree(int nn);

    void asignar(int i, ll x);

    ll consultaR(int a, int b);

    int n;
    vector<nodo> tree;
};

segmentTree::segmentTree(int nn) {
    n = nn;
    tree = vector<nodo>(2*n);
}

void segmentTree::asignar(int i, ll x){
    i += n;
    tree[i].v = x;
    for(i /= 2; i >= 1; i /= 2) tree[i].combinar(tree[2*i],tree[2*i+1]);
}

ll segmentTree::consultaR(int a, int b) {
    a += n; b += n;
    nodo acc;
    while(a <= b){
        if(a % 2 == 1) acc.combinar(acc,tree[a++]);
        if(b % 2 == 0) acc.combinar(acc,tree[b--]);
        a /= 2; b /= 2;
    }
    return acc.v;
}

int trad[N];

void dfs2(vvi& g, vi& p, segmentTree& ord, int nodo, int& pos){
    ord.asignar(nodo,pos);
    trad[pos] = nodo;
    pos++;
    F0(i,g[nodo].size()){
        int hijo = g[nodo][i];
        if(hijo == p[nodo]) continue;
        dfs2(g,p,ord,hijo,pos);
    }
}

void dfs3(vvi& g, vi& p, segmentTree& lca, vi& aparece, int nodo, int prof, int& pos){
    lca.asignar(pos,prof);
    aparece[nodo] = pos;
    pos++;
    F0(i,g[nodo].size()){
        int hijo = g[nodo][i];
        if(hijo == p[nodo]) continue;
        dfs3(g,p,lca,aparece,hijo,prof+1,pos);
        lca.asignar(pos,prof);
        pos++;
    }
}

void e(){
    int n,q;
    cin>>n>>q;
    vi p(n+1);
    REP(i,2,n) cin>>p[i];
    vvi g(n+1);
    REP(v,2,n){
        g[v].pb(p[v]);
        g[p[v]].pb(v);
    }

    segmentTree der(n+1);
    int pos = 1;
    dfs2(g,p,der,1,pos);
    pos = 1;
    segmentTree izq(n+1);
    F1(i,n) izq.asignar(i,-der.consultaR(i,i));

    segmentTree lca(2*n+1);
    vi aparece(n+1);
    pos = 1;
    dfs3(g,p,lca,aparece,1,0,pos);

    int l,r;
    while(q--){
        cin>>l>>r;
        ll m = der.consultaR(l,r);
        der.asignar(trad[m],INF);
        ll d2 = der.consultaR(l,r);
        der.asignar(trad[m],m);
        ll i1 = -izq.consultaR(l,r);
        i1 = trad[i1];
        d2 = trad[d2];
        ll res1 = lca.consultaR(min(aparece[d2],aparece[i1]),max(aparece[d2],aparece[i1]));

        ll m2 = -izq.consultaR(l,r);
        izq.asignar(trad[m2],INF);
        ll i2 = -izq.consultaR(l,r);
        izq.asignar(trad[m2],-m2);
        ll d1 = der.consultaR(l,r);
        d1 = trad[d1];
        i2 = trad[i2];
        ll res2 = lca.consultaR(min(aparece[d1],aparece[i2]),max(aparece[d1],aparece[i2]));

        if(res1 >= res2) cout<<trad[m]<<' '<<res1<<'\n';
        else cout<<trad[m2]<<' '<<res2<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    e();
    return 0;
}