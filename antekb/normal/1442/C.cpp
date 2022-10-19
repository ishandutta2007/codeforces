#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=1e9, mod=998244353, K=20;
const ll INF2=1e18;
ll C=INF;
vector<int> E[2*N];
int n, m;
int solve(){
    //cout<<"a";
    vector<ll> d(n*K, INF2);
    vi ile(n*K);
    d[1]=0;
    set<pair<ld, int> > S;
    for(int i=0; i<n*K; i++){
        S.insert(mp(d[i], i));
    }
    for(int i=1; sz(S); i++){
        int v=(*S.begin()).nd;
        //cout<<v<<" ";
        S.erase(S.begin());
        for(auto u:E[v%(2*n)]){
            int U=u+v/(2*n)*2*n;
            if(U>n*K)continue;
            if(d[v]+1<=d[U]){
                S.erase(S.find(mp(d[U], U)));
                d[U]=d[v]+1;
                S.insert(mp(d[U], U));
            }
        }
        int U=v+n;
        if(U>=n*K)continue;
        if(d[v]<=d[U]){
            S.erase(S.find(mp(d[U], U)));
            d[U]=d[v];
            S.insert(mp(d[U], U));
        }
    }
    //deb(C, ile[n], d[n]);
    //if(d[0]==0)return INF;
    ll ans=INF;
    for(int i=0; i<K; i++){
        //cout<<i<<" "<<d[n*i]<<"\n";
        if(d[n*i])ans=min(ans, d[n*i]+(1<<i)-1);
    }
    //cout<<"b";
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u%=n;
        v%=n;
        E[u].pb(v);
        E[v+n].pb(u+n);
    }
    int a=solve();
    if(a!=INF){
        cout<<a;
        return 0;
    }
    vector<ll> d(2*n, INF2);
    vi ile(2*n);
    d[1]=0;
    set<pair<ld, int> > S;
    for(int i=0; i<2*n; i++){
        S.insert(mp(d[i], i));
    }
    for(int i=1; sz(S); i++){
        int v=(*S.begin()).nd;
        //cout<<v<<" "<<d[v]<<"\n";
        S.erase(S.begin());
        for(auto u:E[v]){
            if(d[v]+1<=d[u]){
                S.erase(S.find(mp(d[u], u)));
                d[u]=d[v]+1;
                ile[u]=ile[v];
                S.insert(mp(d[u], u));
            }
        }
        int u=v+n;
        if(u>=2*n)u-=2*n;
        if(d[u]>C+d[v]){
            S.erase(S.find(mp(d[u], u)));
            d[u]=d[v]+C;
            ile[u]=ile[v]+1;
            S.insert(mp(d[u], u));
        }
    }
    //cout<<"a";
    pll c=mp(d[0]-C*ile[0], ile[0]), b=mp(d[n]-C*ile[n], ile[n]);
    //deb(c.st, c.nd, b.st, b.nd);
    if(d[0]==INF2)c=mp(0, INF);
    if(d[n]==INF)b=mp(0, INF);
    if(c.nd==b.nd && c.st>b.st)swap(c, b);
    if(c.nd>b.nd) swap(c, b);
    int k=c.nd;
    int l=1;
    for(int i=0; i<k; i++){
        l=(l*2)%mod;
    }
    cout<<(l-1+c.st)%mod;
    return 0;
}