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
#define REP(i,a,b) for(ll i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n,d;
    cin>>n>>d;
    vi a(n);
    F0(i,n) cin>>a[i];
    int i = 1;
    while(i < n and i <= d){
        while(i <= d and a[i] > 0){
            a[0]++;
            a[i]--;
            d -= i;
        }
        i++;
    }
    cout<<a[0]<<'\n';
}

void b(){
    int n;
    ll x;
    cin>>n>>x;
    vll a(n);
    F0(i,n) cin>>a[i];
    int i = 0;
    while(i < n and a[i] != x) i++;
    if(i < n){
        cout<<"1\n";
        return;
    }
    ll maxHop = 0;
    F0(i,n) maxi(maxHop,a[i]);
    ll res = (x+maxHop-1)/maxHop;
    maxi(res,(ll)2);
    cout<<res<<'\n';
}

void c(){
    string s;
    cin>>s;
    int n = s.size();
    vi a(n+1);
    F0(i,n) a[i+1] = (int) s[i] - (int) 'a';
    vll ap1(26);
    vvll ap2(26,vll(26));
    F1(i,n){
        F0(c,26){
            ap2[c][a[i]] += ap1[c];
        }
        ap1[a[i]]++;
    }
    ll res = 0;
    F0(i,26) maxi(res,ap1[i]);
    F0(i,26) F0(j,26) maxi(res,ap2[i][j]);
    cout<<res<<'\n';
}

void bfs(vvi& grafo, vi& distancias, int origen){
    queue<pi> q;
    q.push(mp(0,origen));
    int d,nodo;
    while(!q.empty()){
        d = q.front().first;
        nodo = q.front().second;
        q.pop();
        if(distancias[nodo] != -1) continue;
        distancias[nodo] = d;
        F0(i,grafo[nodo].size()) q.push(mp(d+1,grafo[nodo][i]));
    }
}

void d(){
    int n,m,k;
    cin>>n>>m>>k;
    vi a(k);
    F0(i,k) cin>>a[i];
    set<int> special;
    F0(i,k) special.insert(a[i]);
    vvi grafo(n+1);
    int u,v;
    bool haySpecial = false;
    F0(i,m){
        cin>>u>>v;
        if(special.count(u) and special.count(v)) haySpecial = true;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }
    vi distancias1(n+1,-1);
    bfs(grafo,distancias1,1);
    vi distanciasn(n+1,-1);
    bfs(grafo,distanciasn,n);

    if(haySpecial){
        cout<<distancias1[n]<<'\n';
        return;
    }

    vi dp(n,-1);
    F1(u,n){
        if(!special.count(u)) continue;
        int i = distancias1[u];
        if(dp[i] != -1){
            cout<<distancias1[n]<<'\n';
            return;
        }
        dp[i] = distanciasn[u];
    }
    int res = 1;
    int i = 0;
    while(dp[i] == -1) i++;
    while(i < n){
        int j = i+1;
        while(j < n and dp[j] == -1) j++;
        if(j < n) maxi(res,dp[j]+1+i);
        i = j;
    }
    vi dp2(n,-1);
    F1(u,n){
        if(!special.count(u)) continue;
        int i = distanciasn[u];
        if(dp2[i] != -1){
            cout<<distancias1[n]<<'\n';
            return;
        }
        dp2[i] = distancias1[u];
    }
    i = 0;
    while(dp2[i] == -1) i++;
    while(i < n){
        int j = i+1;
        while(j < n and dp[j] == -1) j++;
        if(j < n) maxi(res,dp2[j]+1+i);
        i = j;
    }
    mini(res,distancias1[n]);
    cout<<res<<'\n';
}

void e(){
    int n,m;
    cin>>n>>m;
    vi grass(n);
    F0(i,n) cin>>grass[i];
    vvi vacas(n+1,vi(n+1));
    int f,h;
    F0(i,m){
        cin>>f>>h;
        vacas[f][h]++;
    }
    F1(f,n){
        F1(h,n){
            vacas[f][h] += vacas[f][h-1];
        }
    }

    vi dpizq(n+1);
    vi dpder(n+1);
    F0(i,n){
        dpder[grass[i]]++;
    }
    int maxRes = 0;
    ll formas = 0;
    int i = 0;
    while(i <= n){
        int resi = 0;
        ll formasi = 1;
        if(i > 0){
            int f = grass[i-1];
            int izq = dpizq[f];
            int der = dpder[f];
            if(vacas[f][izq] > vacas[f][izq-1]){
                resi++;
                if(izq <= der){
                    if(vacas[f][der] >= 2) {
                        resi++;
                        formasi *= vacas[f][der]-1;
                        formasi %= mod;
                    }
                }
                else {
                    if(vacas[f][der] >= 1){
                        resi++;
                        formasi *= vacas[f][der];
                        formasi %= mod;
                    }
                }
            }
            else formasi = 0;
        }
        F1(f,n){
            if(i > 0 and f == grass[i-1]) continue;
            int chico = dpizq[f];
            int grande = dpder[f];
            if(chico > grande) swap(chico,grande);
            if(vacas[f][grande] >= 2 and vacas[f][chico] >= 1){
                resi += 2;
                ll conGrande = (vacas[f][grande] - vacas[f][chico]) * vacas[f][chico];
                ll sinGrande = (vacas[f][chico]-1)*vacas[f][chico];
                formasi *= (conGrande+sinGrande);
            }
            else if(vacas[f][grande] >= 1 and vacas[f][chico] == 0) {
                resi++;
                formasi *= (ll) vacas[f][grande];
            }
            else if(vacas[f][chico] >= 1){
                resi++;
                formasi *= (ll) vacas[f][chico]*2;
            }
            formasi %= mod;
        }
        if(i < n){
            dpizq[grass[i]]++;
            dpder[grass[i]]--;
        }
        if(resi == maxRes){
            formas += formasi;
            formas %= mod;
        }
        if(resi > maxRes){
            maxRes = resi;
            formas = formasi;
        }
        i++;
    }
    cout<<maxRes<<' '<<formas<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}