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

struct persistentDSU{
    persistentDSU(int n){
        p.resize(n);
        F0(i,n) p[i] = i;
        s = vi(n,1);
        stack = {{}};
        c = vi(n);
    }

    int find(int u){
        while(u != p[u]) u = p[u];
        return u;
    }

    int color(int u){
        int res = 0;
        while(u != p[u]){
            res++;
            res += c[u];
            u = p[u];
        }
        return res%2;
    }

    bool unite(int u, int v){
        int a = u; int b = v;
        u = find(u);
        v = find(v);
        if(u == v) return color(a) != color(b);
        if(s[u] < s[v]) swap(u,v);
        if(color(a) != color(b)) stack.back().eb(mt(u,v,1));
        else stack.back().eb(mt(u,v,0));
        if(color(a) != color(b)) c[v]++;
        p[v] = u;
        s[u] += s[v];
        return true;
    }

    void persist(){
        stack.eb(vector<tuple<int,int,int>>());
    }

    void rollback(){
        while(!stack.back().empty()){
            int u,v,si;
            tie(u,v,si) = stack.back().back();
            p[v] = v;
            s[u] -= s[v];
            c[v] -= si;
            stack.back().pop_back();
        }
        stack.pop_back();
    }

    vi p;
    vi s;
    vi c;
    vector<vector<tuple<int,int,int>>> stack;
};

vi a;

bool cmp(pi e1, pi e2){
    if(a[e1.first] != a[e2.first]) return a[e1.first] < a[e2.first];
    return a[e1.second] < a[e2.second];
}

void c(){
    int n,m,k,u,v;
    cin>>n>>m>>k;
    a.resize(n);
    F0(i,n) cin>>a[i];
    F0(i,n) a[i]--;
    vb bipartito(k,true);
    vi trad(n);
    vi saiz(k);
    F0(i,n){
        trad[i] = saiz[a[i]];
        saiz[a[i]]++;
    }
    vector<persistentDSU> uf;
    F0(i,k) uf.eb(persistentDSU(saiz[i]));
    vpi E(m);
    F0(i,m) cin>>E[i].first>>E[i].second;
    F0(i,m) E[i].first--;
    F0(i,m) E[i].second--;
    F0(i,m) if(a[E[i].first] > a[E[i].second]) swap(E[i].first,E[i].second);

    sort(todo(E),cmp);

    persistentDSU total(n);
    for(auto e : E){
        if(a[e.first] != a[e.second]) continue;
        int group = a[e.first];
        tie(u,v) = e;
        u = trad[u];
        v = trad[v];
        bipartito[group] = bipartito[group] and uf[group].unite(u,v);
    }
    for(auto e : E){
        if(a[e.first] != a[e.second]) continue;
        int group = a[e.first];
        if(!bipartito[group]) continue;
        tie(u,v) = e;
        total.unite(u,v);
    }

    ll res = 0;
    F0(i,k) if(bipartito[i]) res++;
    res = res * (res-1) / 2;

    int i = 0;
    while(i < m){
        int j = i;
        while(j < m and a[E[j].first] == a[E[i].first] and a[E[j].second] == a[E[i].second]) j++;
        int g1 = a[E[i].first];
        int g2 = a[E[i].second];
        if(g1 != g2 and bipartito[g1] and bipartito[g2]){
            total.persist();
            REP(ii,i,j-1) {
                tie(u,v) = E[ii];
                if(!total.unite(u,v)) {
                    res--;
                    break;
                }
            }
            total.rollback();
        }
        i = j;
    }
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}