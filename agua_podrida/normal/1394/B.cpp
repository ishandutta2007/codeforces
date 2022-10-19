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
#define INF 1000000000000000000
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int m;

void parsear(string& s, string& r, vvi& b, vvi& e){
    map<char,int> trad;
    F0(i,s.size()) trad[s[i]] = trad.size()-1;
    int i = 0;
    while(i < r.size()){
        b.pb({});
        while(r[i] != '>') {
            b.back().pb(trad[r[i]]);
            i++;
        }
        i++;
        e.pb({});
        while(i < r.size() and r[i] != '|'){
            e.back().pb(trad[r[i]]);
            i++;
        }
        i++;
    }
}

int enciende[64],apaga[64];

vvvi armarAFND(vvi& b,vvi& e){
    int n = 1;
    F0(i,b.size()) n += b[i].size();
    F0(i,e.size()) n += e[i].size();
    vvvi afnd(n,vvi(m));
    int state = 0;
    F0(c,m) afnd[0][c].pb(0);
    F0(i,b.size()){
        F0(j,b[i].size()){
            state++;
            if(j == 0) afnd[0][b[i][j]].pb(state);
            else afnd[state-1][b[i][j]].pb(state);
        }
        enciende[state] = i;
    }

    F0(i,e.size()){
        F0(j,e[i].size()){
            state++;
            if(j == 0) afnd[0][e[i][j]].pb(state);
            else afnd[state-1][e[i][j]].pb(state);
        }
        apaga[state] = i;
    }

    return afnd;
}

ll transicion(vvvi& afnd, ll state, int c){
    ll statep = 0;
    F0(i,afnd.size())
        if(state & (1ll<<i))
            F0(j,afnd[i][c].size()) statep |= (1<<(afnd[i][c][j]));
    return statep;
}

ll nuevoBit(ll statep, ll bit){
    F0(i,64){
        if((statep & (1ll<<i)) == 0) continue;
        if(enciende[i] != -1 and ((bit & (1<<enciende[i])) == 0)) bit += (1<<(enciende[i]));
        if(apaga[i] != -1 and (bit & (1<<(apaga[i]))) != 0) bit -= (1<<(apaga[i]));
    }
    return bit;
}

map<ll,vvpll> armarTransiciones(vvvi& afnd, int rules){
    map<ll,vvpll> M;
    queue<ll> q;
    q.push(1);
    ll statep,bitp;
    while(!q.empty()){
        ll state = q.front();
        q.pop();
        if(M.count(state)) continue;
        M[state] = vvpll(1<<rules,vpll(m));
        F0(bit,(1<<rules)){
            F0(c,m){
                statep = transicion(afnd,state,c);
                bitp = nuevoBit(statep,bit);
                M[state][bit][c] = mp(statep,bitp);
            }
        }
        F0(c,m) q.push(transicion(afnd,state,c));
    }
    return M;
}

void h(){
    memset(enciende,-1,sizeof(enciende));
    memset(apaga,-1,sizeof(apaga));
    int k;
    string s,r;
    cin>>k>>s>>r;
    m = s.size();
    vvi b,e;
    parsear(s,r,b,e);

    vvvi afnd = armarAFND(b,e);

    map<ll,vvpll> M = armarTransiciones(afnd,b.size());

    vector<map<ll,vll>> dp(2);
    F0(i,2) {
        forall(it,M){
            ll state = it->first;
            dp[i][state] = vll(1<<b.size());
        }
    }
    dp[0][1][0] = 1;
    ll statep,bitp;
    F0(i,k){
        forall(it,M){
            ll state = it->first;
            F0(bit,(1<<b.size())) dp[(i+1)%2][state][bit] = 0;
        }
        forall(it,M){
            ll state = it->first;
            F0(bit,(1<<b.size())){
                F0(c,m){
                    tie(statep,bitp) = M[state][bit][c];
                    dp[(i+1)%2][statep][bitp] += dp[i%2][state][bit];
                    dp[(i+1)%2][statep][bitp] %= 10000000;
                }
            }
        }
    }
    ll res = 0;
    forall(it,M){
        ll state = it->first;
        res += dp[k%2][state][0];
        res %= 10000000;
    }
    cout<<res<<'\n';
}

void a(){
    int n,d;
    ll m;
    cin>>n>>d>>m;
    ll aux;
    vll menores,mayores;
    F0(i,n) {
        cin>>aux;
        if(aux <= m) menores.pb(aux);
        else mayores.pb(aux);
    }
    sort(todo(menores));
    reverse(todo(menores));
    sort(todo(mayores));
    ll res = 0;
    if(mayores.size() == 0){
        F0(i,n) res += menores[i];
        cout<<res<<'\n';
        return;
    }
    res += mayores.back();
    mayores.pop_back();
    reverse(todo(mayores));

    ll ress = 0;

    F0(i,menores.size()) res += menores[i];
    maxi(ress,res);
    int i = menores.size();
    int j = 0;
    while(j < mayores.size() and i + (j+1)*(d+1) <= n-1) {
        res += mayores[j];
        j++;
    }
    maxi(ress,res);
    while(i > 0){
        i--;
        res -= menores[i];
        while(j < mayores.size() and i + (j+1)*(d+1) <= n-1) {
            res += mayores[j];
            j++;
        }
        maxi(ress,res);
    }
    cout<<ress<<'\n';
}

pi medio(int a1, int b1, int a2, int b2, int d){
    int i = 0;
    while(i*2 < d){
        if(a1 < a2 and b1 < b2) {
            a1++; b1++;
        }
        else if(a1 > a2 and b1 > b2) {
            a1--; b1--;
        }
        else if(a1 < a2) a1++;
        else if(a1 > a2) a1--;
        else if(b1 > b2) b1--;
        else if(b1 < b2) b1++;
        i++;
    }
    return mp(a1,b1);
}

void c(){
    int n;
    cin>>n;
    string s;
    vi a(n);
    vi b(n);
    F0(i,n) {
        cin>>s;
        F0(j,s.size()) {
            if(s[j] == 'B') a[i]++;
            else b[i]++;
        }
    }

    vi dist(n);
    int u = 0;
    F0(i,n){
        if((a[u]-a[i])*(b[u]-a[i]) < 0) dist[i] = abs(a[u]-a[i]) + abs(b[u]-b[i]);
        else dist[i] = max(abs(a[u]-a[i]),abs(b[u]-b[i]));
    }
    F0(i,n) if(dist[i] > dist[u]) u = i;
    F0(i,n){
        if((a[u]-a[i])*(b[u]-a[i]) < 0) dist[i] = abs(a[u]-a[i]) + abs(b[u]-b[i]);
        else dist[i] = max(abs(a[u]-a[i]),abs(b[u]-b[i]));
    }

    int v = u;
    F0(i,n) if(dist[v] < dist[i]) v = i;
    pi m = medio(a[v],b[v],a[u],b[u],dist[v]);

    int res = (dist[v]+1)/2;

    F0(i,n){
        if((m.first-a[i])*(m.second-a[i]) < 0) dist[i] = abs(m.first-a[i]) + abs(m.second-b[i]);
        else dist[i] = max(abs(m.first-a[i]),abs(m.second-b[i]));
    }

    int w = 0;
    F0(i,n) if(dist[i] > dist[w]) w = i;

    m = medio(m.first,m.second,a[w],b[w],dist[w]-res);

    cout<<res<<'\n';
    F0(i,m.first) cout<<'B';
    F0(i,m.second) cout<<'N';
    cout<<'\n';
}

int n,k;

bool siguiente(vi& p){
    int i = k-1;
    while(i >= 0 and p[i] == i){
        p[i] = 0;
        i--;
    }
    if(i == -1) return false;
    p[i]++;
    return true;
}

void b(){
    cin>>n>>m>>k;
    vvpi G(n+1);
    int u,v,w;
    F0(i,m){
        cin>>u>>v>>w;
        G[u].pb(mp(w,v));
    }

    vll val(n+1);
    F1(i,n) val[i] = rand()%1000000000;
    F1(v,n) sort(todo(G[v]));

    vvll s(k,vll(k)); //s[i][j] Union v con grado i next v
    ll goal = 0;
    F1(v,n){
        int i = G[v].size()-1;
        F0(j,G[v].size()){
            s[i][j] += val[G[v][j].second];
            s[i][j] %= mod;
        }
        goal += val[v];
        goal %= mod;
    }

    vi p(k);
    int res = 0;
    do {
        ll suma = 0;
        F0(i,k){
            suma += s[i][p[i]];
            suma %= mod;
        }
        if(suma == goal) res++;
    } while(siguiente(p));
    cout<<res<<'\n';
}

int main() {
    //freopen("../input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    b();
    return 0;
}