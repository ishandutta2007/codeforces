#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;

const int N=2e5+100;
map <pii,int> mp;
pii seg[N*4];
ll lazy[N*4];
pii jam[N*4];
ll hi[N];
ll par[N];
vector <int> g[N];
ll sz[N];
int dfs1(int node){
    hi[node]=hi[par[node]]+1;
    for (int v:g[node]) if (v!=par[node]){
        par[v]=node;
        sz[node]+=dfs1(v);
    }
    return ++sz[node];
}
void shift(ll nod){
    if (lazy[nod]){
        seg[nod*2].F=jam[nod*2].F-seg[nod*2].F;
        seg[nod*2].S=jam[nod*2].S-seg[nod*2].S;
        seg[nod*2+1].F=jam[nod*2+1].F-seg[nod*2+1].F;
        seg[nod*2+1].S=jam[nod*2+1].S-seg[nod*2+1].S;
        lazy[nod*2]=1-lazy[nod*2];
        lazy[nod*2+1]=1-lazy[nod*2+1];
        /*
        if (jam[nod].F!=jam[nod*2].F+jam[nod*2+1].F){
            cout << " itguhnerigeouhtgi3urthgirngkrntkiughnritghnir " << endl;
        }
        if (seg[nod].F!=seg[nod*2].F+seg[nod*2+1].F){
            cout << " eokrgoietjgoirjtgoijrtoijgroitjgoritjgoirjtogijrotijgoritjgor2" << endl;
            cout << nod << endl;
        }
        */
    }
    lazy[nod]=0;
}
/*
void check(ll nod,ll l,ll r){
    if (r-l==1) return ;
    shift(nod);
    ll mid=(l+r)/2;
    check(nod*2,l,mid);
    check(nod*2+1,mid,r);
}
*/
void add(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]={0,0};
        jam[nod]={val,1};
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id) add(nod*2,l,mid,id,val);
    else add(nod*2+1,mid,r,id,val);
    jam[nod].F=jam[nod*2].F+jam[nod*2+1].F;
    jam[nod].S=jam[nod*2].S+jam[nod*2+1].S;
    seg[nod].F=seg[nod*2].F+seg[nod*2+1].F;
    seg[nod].S=seg[nod*2].S+seg[nod*2+1].S;
}
void upd(ll nod,ll l,ll r,ll L,ll R){
    //cout << " mohsen " << nod << " " << l << " " << r << " " << L << " " << R << " " << seg[nod].F << " " << seg[nod].S << endl;
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        lazy[nod]=1-lazy[nod];
        seg[nod].F=jam[nod].F-seg[nod].F;
        seg[nod].S=jam[nod].S-seg[nod].S;
     //  cout << nod << " eoirjgr4n  " << l << " " << r << " " << seg[nod].F << " " << seg[nod].S << endl;
        return ;
    }
    /*
    if (lazy[nod]){
        cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
    }
    */
    shift(nod);
    ll mid=(r+l)/2;
   // cout << " mamad2 " << nod << " " << l << " " << r << " " << seg[nod].F << " " << seg[nod].S << endl;

    upd(nod*2,l,mid,L,R);
    upd(nod*2+1,mid,r,L,R);
    jam[nod].F=jam[nod*2].F+jam[nod*2+1].F;
    jam[nod].S=jam[nod*2].S+jam[nod*2+1].S;
    seg[nod].F=seg[nod*2].F+seg[nod*2+1].F;
    seg[nod].S=seg[nod*2].S+seg[nod*2+1].S;
    //cout << " mamad " << nod << " " << l << " " << r << " " << seg[nod].F << " " << seg[nod].S << endl;
}
ll head[N],st[N],fn[N],ts=1;
void dfs2(int node, int hd){
    head[node]=hd;
    st[node]=ts;
    int big=0;
    for (int v:g[node]) if (v!=par[node] && sz[v]>sz[big]) big=v;
    if (big) ts++,dfs2(big, hd);
    for (int v:g[node]) if (v!=par[node] && v!=big) ts++,dfs2(v, v);
    fn[node]=ts;
}
ll n;
void GetPath(int u, int v){
    while (head[u]!=head[v]){
        if (hi[head[u]]>hi[head[v]]) swap(u, v);
        upd(1, 1, n+1, st[head[v]], st[v]+1);
        //check(1,1,n+1);
       // cout << st[head[v]] << " type1 " << st[v]+1 << endl;
        v=par[head[v]];
    }
    if (hi[u]>hi[v]) swap(u, v);
    //cout << st[u] << " type2 " << st[v]+1 << endl;
    //check(1,1,n+1);
    //cout << " type3 " << endl;
    upd(1, 1, n+1, st[u], st[v]+1);
    //check(1,1,n+1);
    //cout << st[u] << " type2 " << st[v]+1 << endl;
}
ll ss[N];
ll active[N];
void dfs3(ll v,ll p,vector <int> &ans){
    ss[v]=1;
    for (auto u : g[v]){
        if (active[u] && u!=p){
            dfs3(u,v,ans);
            ss[v]+=ss[u];
        }
    }
    if (ss[v]%2==1){
        ans.pb(mp[{v,p}]);
    }
}
int32_t main(){
    sync;
    cin >> n;
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        mp[{u,v}]=i+1;
        mp[{v,u}]=i+1;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1);
    dfs2(1,1);
    add(1,1,n+1,st[1],0);
    GetPath(1,1);
   // cout << seg[1].F << " " << seg[1].S  << endl;
    ll cnt=1;
    active[1]=1;
    while(1){
        ll t;
        cin >> t;
        if (t==3) break;
        if (t==1){
            ll x;
            cin >> x;
            active[x]=1;
            //cout << head[x] << endl;
            cnt++;
           // check(1,1,n+1);
            add(1,1,n+1,st[x],mp[{x,par[x]}]);
            //check(1,1,n+1);
            //cout << " check " << endl;
            GetPath(1,x);
            //cout << jam[1].F << " " << jam[1].S << " " << seg[1].S << endl;
            if (cnt%2==0 && seg[1].S*2==cnt){
                cout << seg[1].F << endl;
            }
            else cout << 0 << endl;
        }
        else{
            if (!(cnt%2==0 && seg[1].S*2==cnt)){
                cout << 0 << endl;
            }
            else{
                vector <int> ans;
                dfs3(1,1,ans);
                sort(ans.begin(),ans.end());
                cout << ans.size() << " ";
                for (auto u : ans){
                    cout << u << " ";
                }
                cout << endl;
            }
        }
     //   cout << seg[1].F << " erhgieurhgi4rhgirn " << seg[1].S << endl;
       /// check(1,1,n+1);
    }
    return 0;
}