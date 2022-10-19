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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    string res;
    while(n >= 4){
        res.pb('1');
        n -= 2;
    }
    if(n == 2) res.pb('1');
    else res.pb('7');

    F0R(i,res.size()) cout<<res[i];
    cout<<'\n';
}

void b(){
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vi suma(2*n);
    int total = 0;
    F0(i,n) {
        suma[total+n]++;
        if(s[i] == '1') total--;
        else total++;
    }

    if(total == 0){
        total = 0;
        F0(i,n){
            if(total == x) {
                cout<<"-1\n";
                return;
            }
            if(s[i] == '1') total--;
            else total++;
        }
    }

    // invierto tod o para que total > 0
    if(total < 0){
        F1(i,n-1) swap(suma[i],suma[2*n-i]);
        total = -total;
        x = -x;
    }

    int aux = x;

    int res = 0;
    x %= total;
    x += total;
    x %= total;
    for(int i = x; i < n and i <= aux; i += total) res += suma[n+i];
    for(int i = x-total; i > -n and i <= aux; i -= total) res += suma[n+i];
    cout<<res<<'\n';
}

void bb(){
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vi suma(2*n);
    int total = 0;
    F0(i,n){
        suma[total+n]++;
        if(s[i] == '1') total--;
        else total++;
    }

    if(total == 0){
        if(0 <= x+n and x+n < 2*n and suma[x+n]) cout<<-1<<'\n';
        else cout<<0<<'\n';
        return;
    }

    if(total < 0){
        F0(i,n) {
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
        F0(i,2*n) suma[i] = 0;
        total = 0;
        F0(i,n){
            suma[total+n]++;
            if(s[i] == '1') total--;
            else total++;
        }
        x = -x;
    }

    int aux = x;
    x %= total;
    x += total;
    x %= total;
    int res = 0;
    for(int i = x; i < n and i <= aux; i += total) res += suma[i+n];
    for(int i = min(x-total,aux); i > -n; i -= total) res += suma[i+n];
    cout<<res<<'\n';
}

void c(){
    string s;
    string t;
    cin>>s>>t;
    map<char,set<int>> coso;
    F0(i,s.size()) coso[s[i]].insert(i);
    int res = 1;
    int i = 0;
    int j = -1;
    auto it = coso[t[0]].end();
    while(i < t.size()){
        if(coso[t[i]].empty()){
            cout<<"-1\n";
            return;
        }

        it = coso[t[i]].upper_bound(j);
        if(it != coso[t[i]].end() and *it < s.size()) {
            j = *it;
            i++;
        }
        else {
            j = -1;
            res++;
        }
    }
    cout<<res<<'\n';
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

vpll factorizar(ll m){
    ll factor = 2;
    ll alfa;
    vpll res;
    while(factor*factor <= m){
        alfa = 0;
        while(m%factor == 0) {
            m /= factor;
            alfa++;
        }
        if(alfa) res.pb(mp(factor,alfa));
        factor++;
    }
    if(m != 1) res.pb(mp(m,1));
    return res;
}

void d(){
    ll a,m;
    cin>>a>>m;
    ll d = gcd(a,m);
    a /= d;
    m /= d;
    vpll p = factorizar(m);
    ll phi = 1;
    F0(i,p.size()) {
        F0(j,p[i].S-1) phi *= p[i].F;
        phi *= p[i].F-1;
    }
    cout<<phi<<'\n';
}


struct lazySegmentTreeMax {

    lazySegmentTreeMax(int nn);

    ll maxr(int a, int b, int nodo, int x, int y);

    void add(int a, int b, ll val, int nodo, int x, int y);

    int n;
    vll tree;
    vll lazy;
};

lazySegmentTreeMax::lazySegmentTreeMax(int nn) {
    n = nn;
    tree = vll(4*n);
    lazy = vll(4*n);
}

ll lazySegmentTreeMax::maxr(int a, int b, int nodo, int x, int y){
    if(b < x or y < a) return -INF;
    if(lazy[nodo]){
        if(x != y){
            lazy[2*nodo] += lazy[nodo];
            lazy[2*nodo+1] += lazy[nodo];
        }
        tree[nodo] += lazy[nodo];
        lazy[nodo] = 0;
    }
    if(a <= x and y <= b) return tree[nodo];
    int d = (x+y)/2;
    ll resIzq = maxr(a,b,2*nodo,x,d);
    ll resDer = maxr(a,b,2*nodo+1,d+1,y);
    return max(resIzq,resDer);
}

void lazySegmentTreeMax::add(int a, int b, ll val, int nodo, int x, int y) {
    if(lazy[nodo]){
        if(x != y){
            lazy[2*nodo] += lazy[nodo];
            lazy[2*nodo+1] += lazy[nodo];
        }
        tree[nodo] += lazy[nodo];
        lazy[nodo] = 0;
    }
    if(b < x or y < a) return;
    if(a <= x and b >= y){
        tree[nodo] += val;
        if(x != y) {
            lazy[2*nodo] += val;
            lazy[2*nodo+1] += val;
        }
        return;
    }

    int d = (x+y)/2;
    add(a,b,val,nodo*2,x,d);
    add(a,b,val,nodo*2+1,d+1,y);
    tree[nodo] = max(tree[2*nodo],tree[2*nodo+1]);
}

void e(){
    int n;
    cin>>n;
    vi p(n+1);
    F1(i,n) cin>>p[i];
    vi pos(n+1);
    F1(i,n) pos[p[i]] = i;
    vll costo(n+1);
    F1(i,n) cin>>costo[i];

    ll res = INF;

    lazySegmentTreeMax t(n+1);
    F1(i,n) t.add(pos[i],n-1,-costo[pos[i]],1,0,n);
    F1(x,n-1){
        t.add(pos[x],n-1,costo[pos[x]],1,0,n);
        t.add(1,pos[x]-1,-costo[pos[x]],1,0,n);
        mini(res,-t.maxr(1,n-1,1,0,n));
    }

    mini(res,costo[1]);
    mini(res,costo[n]);
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) bb();
    return 0;
}