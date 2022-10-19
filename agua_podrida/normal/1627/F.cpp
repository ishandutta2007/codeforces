#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 998244353;
const int INF  = 1e9;
const double eps = 0.00000001;

int n,k;
pi x,y;
vector<map<int,int>> g;
vi dist;

int id(int i, int j){
    return i*(k+1)+j;
}

int id(pi a){
    return id(a.first,a.second);
}

void negar(pi& a){
    a.first = k-a.first+1;
    a.second = k-a.second+1;
}

void dijkstra(int v){
    int d;
    priority_queue<pi> q;
    q.push({0,v});
    while(!q.empty()){
        tie(d,v) = q.top();
        d = -d;
        q.pop();
        if(dist[v] != INF) continue;
        dist[v] = d;
        for(auto uw : g[v])
            q.push({-d-uw.second,uw.first});
    }
}

void f(){
    cin>>n>>k;
    g = vector<map<int,int>>((k+1)*(k+1));
    dist = vi((k+1)*(k+1),INF);
    F0(i,k) F0(j,k+1) g[id(i,j)][id(i+1,j)] = g[id(i+1,j)][id(i,j)] = 0;
    F0(i,k+1) F0(j,k) g[id(i,j)][id(i,j+1)] = g[id(i,j+1)][id(i,j)] = 0;
    pi a,b;
    F0(i,n){
        cin>>a.first>>a.second>>b.first>>b.second;
        if(a > b) swap(a,b);
        y = a;
        if(a.first == b.first) x = {a.first-1,a.second};
        else x = {a.first,a.second-1};
        g[id(x)][id(y)]++;
        g[id(y)][id(x)]++;
        negar(a), negar(b),swap(a,b);
        y = a;
        if(a.first == b.first) x = {a.first-1,a.second};
        else x = {a.first,a.second-1};
        g[id(x)][id(y)]++;
        g[id(y)][id(x)]++;
    }

    dijkstra(id(k/2,k/2));

    int res = INF;
    F0(i,k+1){
        mini(res,dist[id(i,0)]);
        mini(res,dist[id(i,k)]);
        mini(res,dist[id(0,i)]);
        mini(res,dist[id(k,i)]);
    }
    cout<<n-res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) f();
}