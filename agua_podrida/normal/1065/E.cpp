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
#define mod 998244353

void a(){
    ll s,a,b,c;
    cin>>s>>a>>b>>c;
    s /= c;
    ll res = (s/a) * (a+b);
    res += s % a;
    cout<<res<<'\n';
}

void b(){
    ll n,m;
    cin>>n>>m;
    ll a,b;
    if(m*2 >= n) a = 0;
    else a = n-2*m;

    b = 0;
    while(b*(b-1) < 2*m) b++;
    b = n-b;

    cout<<a<<' '<<b<<'\n';
}

void c(){
    ll n,k;
    cin>>n>>k;
    vll h(n);
    F0(i,n) cin>>h[i];
    sort(todo(h));
    reverse(todo(h));
    int res = 0;
    int i = 0; //intervalo [0..i] miden h[i]
    ll alt = h[0];
    while(i < n and h[i] == alt) i++;
    while(i < n){
        ll corto = 0;

        while(true){
            while(i < n and h[i] == alt) i++;
            if(corto + (ll) i <= k){
                corto += (ll) i;
                alt--;
            }
            else break;
        }

        res++;
    }
    cout<<res<<'\n';
}

int n;

void floyd(vvvvi& d){
    F0(ik,n){
        F0(jk,n){
            F0(i1,n) {
                F0(j1,n){
                    F0(i2,n){
                        F0(j2,n){
                            mini(d[i1][j1][i2][j2],d[i1][j1][ik][jk] + d[ik][jk][i2][j2]);
                        }
                    }
                }
            }
        }
    }
}

void cab(vvvvi& d){
    F0(i1,n) {
        F0(j1,n){
            F0(i2,n){
                F0(j2,n){
                    if(abs(i1-i2) + abs(j1-j2) == 3 and i1 != i2 and j1 != j2) d[i1][j1][i2][j2] = 1;
                }
            }
        }
    }
    F0(i,n) F0(j,n) d[i][j][i][j] = 0;
}

void rook(vvvvi& d){
    F0(i1,n){
        F0(j1,n){
            F0(i2,n){
                F0(j2,n){
                    if((i1 == i2 and j1 != j2) or (i1 != i2 and j1 == j2)) d[i1][j1][i2][j2] = 1;
                }
            }
        }
    }
    F0(i,n) F0(j,n) d[i][j][i][j] = 0;
}

void alf(vvvvi& d){
    F0(i1,n){
        F0(j1,n){
            F0(i2,n){
                F0(j2,n){
                    if(i1+j1 == i2+j2 or i1-j1 == i2-j2) d[i1][j1][i2][j2] = 1;
                }
            }
        }
    }
    F0(i,n) F0(j,n) d[i][j][i][j] = 0;
}

void d(){
    cin>>n;
    vvi t(n,vi(n));
    F0(i,n) F0(j,n) cin>>t[i][j];

    vvvvi distCab(n,vvvi(n,vvi(n,vi(n,INF))));
    cab(distCab);
    floyd(distCab);
    vvvvi distRook(n,vvvi(n,vvi(n,vi(n,INF))));
    rook(distRook);
    floyd(distRook);
    vvvvi distAlf(n,vvvi(n,vvi(n,vi(n,INF))));
    alf(distAlf);
    floyd(distAlf);

    vvpi dp(n*n+1,vpi(3,{INF,INF})); //0: cab, 1: rook, 2: alf
    dp[1][0] = {0,0};
    dp[1][1] = {0,0};
    dp[1][2] = {0,0};
    int i,j;
    int ip,jp;
    int estoy = 1;
    while(estoy != n*n){
        F0(i1,n) F0(j1,n) {
            if(t[i1][j1] == estoy) {
                i = i1;
                j = j1;
            }
        }
        estoy++;
        F0(i1,n) F0(j1,n) {
            if(t[i1][j1] == estoy) {
                ip = i1;
                jp = j1;
            }
        }

        F0(c,3){
            F0(cp,3){
                int mov = dp[estoy-1][c].first;
                if(cp == 0) mov += distCab[i][j][ip][jp];
                if(cp == 1) mov += distRook[i][j][ip][jp];
                if(cp == 2) mov += distAlf[i][j][ip][jp];
                int camb = dp[estoy-1][c].second;
                if(cp != c) {
                    mov++;
                    camb++;
                }
                mini(dp[estoy][cp],mp(mov,camb));
            }
        }
    }

    pi res = {INF,0};
    F0(c,3) mini(res,dp[n*n][c]);
    cout<<res.first<<' '<<res.second<<'\n';
}

struct state{
    state(){
        i = 0;
        j = 0;
        p = 0;
        v = 0;
    }
    state(int _i, int _j, int _p, int _v){
        i = _i;
        j = _j;
        p = _p;
        v = _v;
    }

    bool operator<(state o)const {
        if(i != o.i) return i < o.i;
        if(j != o.j) return j < o.j;
        if(p != o.p) return p < o.p;
        return v < o.v;
    }
    int i;
    int j;
    int p;
    int v;
};

struct dis{
    dis(){
        steps = 0;
        cambios = 0;
    }
    dis(int s, int c){
        steps = s;
        cambios = c;
    }
    bool operator<(dis otro) const{
        if(steps != otro.steps) return steps > otro.steps;
        return cambios > otro.cambios;
    }
    int steps;
    int cambios;
};

bool caballo(int i1, int j1, int i2, int j2){
    return (abs(i1-i2) + abs(j1-j2) == 3 and i1 != i2 and j1 != j2);
}

bool torre(int i1, int j1, int i2, int j2){
    return i1 == i2 or j1 == j2 and (i1 != i2 or j1 != j2);
}

bool alfil(int i1, int j1, int i2, int j2){
    if(i1 == i2 and j1 == j2) return false;
    return i1 + j1 == i2 + j2 or i1 - j1 == i2 - j2;
}

bool seMueve(state nodo, int i, int j){
    if(nodo.p == 0) return caballo(nodo.i,nodo.j,i,j);
    if(nodo.p == 1) return torre(nodo.i,nodo.j,i,j);
    if(nodo.p == 2) return alfil(nodo.i,nodo.j,i,j);
}

void dijkstra(vvi& t, map<state,dis>& d, state origen){
    priority_queue<pair<dis,state>> q;
    q.push(mp(dis(0,0),origen));
    origen.p = 1;
    q.push(mp(dis(0,0),origen));
    origen.p = 2;
    q.push(mp(dis(0,0),origen));
    state nodo(0,0,0,0);
    dis dNodo(0,0);
    while(!q.empty()){
        dNodo = q.top().first;
        nodo = q.top().second;
        q.pop();
        if(d.count(nodo)) continue;
        if(nodo.v == n*n) {
            cout<<dNodo.steps<<' '<<dNodo.cambios<<'\n';
            return;
        }
        d[nodo] = dNodo;
        if(t[nodo.i][nodo.j] == nodo.v+1) {
            nodo.v++;
            q.push(mp(dNodo,nodo));
            continue;
        }
        dNodo.steps++;
        F0(i,n) F0(j,n) if(seMueve(nodo,i,j)) q.push(mp(dNodo,state(i,j,nodo.p,nodo.v)));
        dNodo.cambios++;
        F0(c,3) q.push(mp(dNodo,state(nodo.i,nodo.j,c,nodo.v)));
    }
}

void d2(){
    cin>>n;
    vvi t(n,vi(n));
    F0(i,n) F0(j,n) cin>>t[i][j];

    map<state,dis> d;
    int i,j;
    F0(i1,n) F0(j1,n) {
        if(t[i1][j1] == 1) {
            i = i1;
            j = j1;
        }
    }
    state origen(i,j,0,1);
    dijkstra(t,d,origen);
}

ll pot(ll b, ll exp){
    if(exp == 0) return 1;
    ll a = pot(b,exp/2);
    a *= a;
    a %= mod;
    if(exp % 2 == 1) a *= b;
    a %= mod;
    return a;
}

void e(){
    ll n,m,a;
    cin>>n>>m>>a;

    vll b(m+1);
    F1(i,m) cin>>b[i];

    ll inv = pot(2,mod-2);
    ll res = pot(a,n - 2*b[m]);
    F1(i,m){
        ll delta = b[i] - b[i-1];
        res *= 2*pot(a,delta) + (pot(a,delta) * (pot(a,delta) - 1)) % mod;
        res %= mod;
        res += mod;
        res %= mod;
        res *= inv;
        res %= mod;
        res += mod;
        res %= mod;
    }

    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    e();
    return 0;
}