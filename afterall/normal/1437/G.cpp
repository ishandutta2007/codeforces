#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5+100,M=26;
int C[N][M],ts=0,F[N];
int ras[N];
bool vis[N];
vector <int> g[N];
set <pii> seg[N*4];
ll st[N],fn[N],tss=1;
void add(string x,ll id){
    int now=0;
    for (char ch : x){
        if (!C[now][ch-'a']){
            C[now][ch-'a']=++ts;
        }
        now=C[now][ch-'a'];
    }
    ras[id]=now;
   // cout << now << " " << t << endl;
}
void build_aho(){
    queue <int> Q;
    for (int i=0;i<M;i++) if (C[0][i]) Q.push(C[0][i]);
    while(Q.size()){
        ll v=Q.front();
        Q.pop();
        g[F[v]].pb(v);
      //  cout << F[v] << " yal " << v << endl;
        for (int i=0;i<M;i++){
            if (!C[v][i]) C[v][i]=C[F[v]][i];
            else{
                Q.push(C[v][i]),F[C[v][i]]=C[F[v]][i];
            }
        }
    }
}
ll dfs(ll v,ll p){
    st[v]=tss;
    for (auto u : g[v]){
        if (u==p) continue;
        tss++;
        dfs(u,v);
    }
    fn[v]=tss+1;
}
ll val[N];
void upd(ll nod,ll l,ll r,ll L,ll R,pii vall){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].insert(vall);
        return ;
    }
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,vall);
    upd(nod*2+1,mid,r,L,R,vall);
}
void del(ll nod,ll l,ll r,ll L,ll R,pii vall){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].erase(vall);
        return ;
    }
    ll mid=(r+l)/2;
    del(nod*2,l,mid,L,R,vall);
    del(nod*2+1,mid,r,L,R,vall);
}
ll get(ll nod,ll l,ll r,ll id){
    if (r-l==1){
        if (seg[nod].size()==0) return -1;
        return seg[nod].rbegin()->F;
    }
    ll mid=(r+l)/2;
    ll ans=-1;
    if (mid>id) ans=get(nod*2,l,mid,id);
    else ans=get(nod*2+1,mid,r,id);
    if (seg[nod].size()!=0) ans=max(ans,seg[nod].rbegin()->F);
    return ans;
}
int32_t main(){
    sync;
    ll n,q;
    memset(val,-1,sizeof val);
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        add(s,i);
        val[i]=0;
    }
    build_aho();
    dfs(0,0);

    for (int i=1;i<=n;i++){
        ll v=ras[i];
        upd(1,1,N,st[v],fn[v],{0,i});
    }
    while(q--){
        ll t;
        cin >> t;
        if (t==2){
            string s;
            cin >> s;
            ll ans=-1;
            ll now=0;
            for (int i=0;i<s.size();i++){
                now=C[now][s[i]-'a'];
                ans=max(ans,get(1,1,N,st[now]));
            }
            cout << ans << endl;
        }
        else{
            ll id,vall;
            cin >> id >> vall;
            ll z=id;
            id=ras[id];
            del(1,1,N,st[id],fn[id],{val[z],z});
            val[z]=vall;
            upd(1,1,N,st[id],fn[id],{val[z],z});
        }
    }

}