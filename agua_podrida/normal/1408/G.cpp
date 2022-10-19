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
#define mod 998244353
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

vll mergear(vll a, vll b){
    vll res(a.size() + b.size() - 1);
    F1(i,a.size()-1) F1(j,b.size()-1) res[i+j] = (res[i+j] + a[i] * b[j]) % mod;
    return res;
}

void g(){
    int n;
    cin>>n;
    int m = n*(n-1)/2;
    vi u(m+1),v(m+1);
    int aux;
    F1(i,n){
        F1(j,n){
            cin>>aux;
            u[aux] = i;
            v[aux] = j;
        }
    }
    vi donde(n+1);
    F1(i,n) donde[i] = i;
    vi peso(n+1,1);
    vvll res(n+1,{0,1});
    vi cantAristas(n+1,0);
    vvi comp(n+1);
    F1(i,n) comp[i].pb(i);

    F1(i,m){
        u[i] = donde[u[i]];
        v[i] = donde[v[i]];
        if(u[i] != v[i]){
            if(peso[u[i]] < peso[v[i]]) swap(u[i],v[i]);
            for(auto nodo : comp[v[i]]){
                comp[u[i]].pb(nodo);
                donde[nodo] = u[i];
            }
            comp[v[i]].clear();
            res[u[i]] = mergear(res[u[i]],res[v[i]]);
            peso[u[i]] += peso[v[i]];
            cantAristas[u[i]] += cantAristas[v[i]];
        }
        cantAristas[u[i]]++;
        if(cantAristas[u[i]] == (peso[u[i]] * (peso[u[i]]-1) / 2)) res[u[i]][1] = 1;
    }

    F1(i,n) cout<<res[donde[1]][i]<<' ';
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    g();
    return 0;
}