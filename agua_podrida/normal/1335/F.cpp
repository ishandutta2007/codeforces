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

void b(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<char> res(n);
    res[0] = 'a';
    F1(i,n-1) {
        if (i >= a) res[i] = res[i - a];
        else if ((int) res[i - 1] - (int) 'a' < b-1) res[i] = (char) ((int) res[i-1]+1);
        else res[i] = res[i-1];
    }
    F0(i,n) cout<<res[i];
    cout<<'\n';
}

void c(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));
    int diferentes = 0;
    F0(i,n) if(i == 0 or a[i] != a[i-1]) diferentes++;
    int res = 0;
    int i = 0;
    while(i<n){
        int j = i;
        while(j < n and a[i] == a[j]) j++;
        maxi(res,min(j-i,diferentes-1));
        maxi(res,min(j-i-1,diferentes));
        i = j;
    }
    cout<<res<<'\n';
}

void d(){
    int n = 9;
    vector<string> s(n);
    F0(i,n) cin>>s[i];
    F0(i,n) F0(j,n) if(s[i][j] == '1') s[i][j] = '2';

    F0(i,n) cout<<s[i]<<'\n';

}

int maxai = 200;

int e(){
    int n;
    cin>>n;
    vi a(n+1);
    F1(i,n) cin>>a[i];

    vvi ap(maxai+1,vi(n+1));
    F1(i,maxai) F1(j,n) {
        ap[i][j] = ap[i][j-1];
        if(a[j] == i) ap[i][j]++;
    }

    int res = 1;
    F1(x,maxai){
        int l = 1;
        int r = n;
        while(l <= n and a[l] != x) l++;
        while(r >= 1 and a[r] != x) r--;
        int len = 1;
        while(l < r){
            F1(y,maxai) maxi(res,2*len+ap[y][r-1]-ap[y][l]);
            l++;
            r--;
            while(l <= n and a[l] != x) l++;
            while(r >= 1 and a[r] != x) r--;
            len++;
        }
    }
    cout<<res<<'\n';
}

void mover(int& i, int& j, char m){
    if(m == 'U') i--;
    if(m == 'D') i++;
    if(m == 'R') j++;
    if(m == 'L') j--;
}

void dfs(vvi& visita, vector<string>& mov, int i, int j, vpi& c, int it){
    while(visita[i][j] == 0){
        visita[i][j] = it;
        mover(i,j,mov[i][j]);
    }
    if(it == visita[i][j]) c.pb(mp(i,j));
}

pi calcular(vector<string>& mov, vvpi& dp, int i, int j){
    if(dp[i][j] != mp(-1,-1)) return dp[i][j];
    int ip = i,jp = j;
    mover(ip,jp,mov[i][j]);
    dp[i][j] = calcular(mov,dp,ip,jp);
    dp[i][j].second++;
    return dp[i][j];
}

vi tamPorCiclo;
vvb negroPorCiclo;

void f(){
    int n,m;
    cin>>n>>m;
    vector<string> color(n);
    vector<string> mov(n);
    F0(i,n) cin>>color[i];
    F0(i,n) cin>>mov[i];
    vvi visita(n,vi(m));
    vpi c;
    int it = 0;
    F0(i,n){
        F0(j,m){
            if(visita[i][j] != 0) continue;
            it++;
            dfs(visita,mov,i,j,c,it);
        }
    }
    tamPorCiclo = vi(c.size());
    negroPorCiclo = vvb(c.size());
    F0(k,c.size()){
        int i = c[k].first;
        int j = c[k].second;
        do {
            mover(i,j,mov[i][j]);
            tamPorCiclo[k]++;
        } while(i != c[k].first or j != c[k].second);
        negroPorCiclo[k] = vb(tamPorCiclo[k],false);
    }
    vvpi dp(n,vpi(m,mp(-1,-1)));
    F0(k,c.size()) dp[c[k].first][c[k].second] = mp(k,0);

    F0(i,n) F0(j,m) dp[i][j] = calcular(mov,dp,i,j);
    F0(i,n) F0(j,m){
        if(color[i][j] == '1') continue;
        int k = dp[i][j].first;
        int d = dp[i][j].second;
        d %= negroPorCiclo[k].size();
        negroPorCiclo[k][d] = true;
    }

    int total = 0;
    int black = 0;
    F0(i,negroPorCiclo.size()){
        F0(j,negroPorCiclo[i].size()) if(negroPorCiclo[i][j]) black++;
        total += tamPorCiclo[i];
    }
    cout<<total<<' '<<black<<'\n';
}

int main() {
    //freopen("../input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) f();
    return 0;
}