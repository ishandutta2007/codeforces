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

const int K=18, N=(1<<K), INF=1e9+5, mod=1e9+7;
int pot[N];
struct node{
    node*l=nullptr, *r=nullptr;
    int h=0, val=0;
    node(){};
    void init(node*v){
        if(!v)return;
        l=v->l;
        r=v->r;
        h=v->h;
        val=v->val;
    }
};
node*left(node*v){
    if(!v)return nullptr;
    return v->l;
}
node*right(node*v){
    if(!v)return nullptr;
    return v->r;
}
int Val(node*v){
    if(!v)return 0;
    return v->val;
}
int H(node*v){
    if(!v)return 0;
    return v->h;
}
void upd(node*v, int S){
    if(!v)return;
    v->val=Val(right(v))+Val(left(v));
    v->h=(pot[S]*1ll*H(right(v))+H(left(v)))%mod;
}
int add(node*v, node*u, int k, int S){
    //cout<<k<<" "<<S<<"\n";
    if(k==0 && u->val==S){
        u->val=0;
        u->h=0;
        u->l=nullptr;
        u->r=nullptr;
        return 1;
    }
    if(k==0 && S==1){
        u->val=1;
        u->h=1;
        return 0;
    }
    u->l=new node();
    u->l->init(left(v));
    u->r=new node();
    u->r->init(right(v));
    bool b=0;
    if(k<S/2){
        b=add(left(v), left(u), k, S/2);
        //if(b)u->l=nullptr;
    }
    if(k>=S/2 || b){
        b=0;
        b=add(right(v), right(u), max(0, k-(S/2)), S/2);
        //if(b)u->r=nullptr;
    }
    upd(u, S/2);
    return b;
}
bool cmp(node*u, node*v){
    //cout<<H(u)<<" "<<H(v)<<"\n";
    if(H(right(u))!=H(right(v)))return cmp(right(u), right(v));
    if(H(left(u))!=H(left(v)))return cmp(left(u), left(v));
    return Val(u)<Val(v);
}
struct comp {
  bool operator() (const pair<node*, int>& lhs, const pair<node*, int>& rhs) const{
        if(H(lhs.st)==H(rhs.st))return lhs.nd<rhs.nd;
        return cmp(lhs.st, rhs.st);
    }
};
vii E[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pot[0]=1;
    for(int i=1; i<N; i++){
        pot[i]=(pot[i-1]<<1)%mod;
    }
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        E[u].pb(mp(v, c));
        E[v].pb(mp(u, c));
    }
    vector<node*> d(n+1);
    int s, t;
    cin>>s>>t;
    d[s]=nullptr;
    d[0]=new node();
    //cout<<"a";
    add(nullptr, d[0], N-1, N);
    //cout<<"a";
    set<pair<node*, int>, comp> S;
    for(int i=1; i<=n; i++){
        if(i!=s)d[i]=d[0];
        S.insert(mp(d[i], i));
    }
    vi par(n+1);
    while(S.size()){
        /*for(int i=1; i<=n; i++)cout<<H(d[i])<<" ";
        cout<<"\n";*/
        int v=(*S.begin()).nd;
        S.erase(S.begin());
        //cout<<v<<" "<<H(d[v])<<"\n";
        //cout<<v<<"\n";
        for(pii u:E[v]){
            node* w=new node();
            add(d[v], w, u.nd, N);
            //cout<<v<<" "<<u.st<<" "<<H(w)<<"\n";
            if(H(w)!=H(d[u.st]) && cmp(w, d[u.st])){
                par[u.st]=v;
                S.erase(S.find(mp(d[u.st], u.st)));
                d[u.st]=w;
                S.insert(mp(d[u.st], u.st));
            }
        }
    }
    if(d[t]==d[0]){
        cout<<"-1";
        return 0;
    }
    cout<<H(d[t])<<"\n";
    vi path;
    path.pb(t);
    while(par[path.back()])path.pb(par[path.back()]);
    cout<<path.size()<<"\n";
    rev(path);
    for(int i:path)cout<<i<<" ";
}