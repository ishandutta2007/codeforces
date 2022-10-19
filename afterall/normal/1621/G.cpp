#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;

const int N=2e5+100;
ll a[N];
ll dp[N];
ll DP[N];
ll pd[N];
ll nxt[N];
ll mod=1e9+7;
vector <int> fen[N];
void add(ll ID,ll idx,ll val){
    for (;idx<fen[ID].size();idx += idx & (-idx)){
        fen[ID][idx]+=val;
    }
}
ll get(ll ID,ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)) s+=fen[ID][idx];
    return s;
}
void build(ll id,ll sz){
    fen[id].resize(sz);
    for (int i=0;i<fen[id].size();i++) fen[id][i]=0;
}

map <int,int> mp;
ll vis[N];
vector <int> W[N];
vector <pii> y[N];
ll E[N];
int Main(){
    mp.clear();
    ll n;
    cin >> n;
    vector <pii> w;
    for (int i=1;i<=n;i++){
        E[i]=0;
        y[i].clear();
        W[i].clear();
        fen[i].clear();
        dp[i]=0;
        pd[i]=0;
        DP[i]=0;
        nxt[i]=0;
        vis[i]=0;
        cin >> a[i];
        w.pb({a[i],-i});
    }
    fen[n+1].clear();
    build(n+1,n+3);
    sort(w.begin(),w.end());
    for (int i=0;i<w.size();i++) a[-w[i].S]=i+1;
    for (int i=1;i<=n;i++) W[a[i]].pb(i);

    fen[0].clear();
    build(0,n+3);
    ll ans=0;
    for (int i=1;i<=n;i++){
        pd[i]=1+get(0,a[i]-1);
        pd[i]%=mod;
        add(0,a[i],pd[i]);
    }
    for (int i=n;i;i--){
        for (int j=a[i]-1;j;j--) {
            if (vis[j]!=0) break;
            vis[j]=1;
            for (auto u : W[j]) nxt[u]=i;
        }
        if (nxt[i]==0){
            nxt[i]=i;
            dp[i]=1;
            vis[a[i]]=1;
        }
    }
    for (int i=1;i<=n;i++){
        y[nxt[i]].pb({a[i],i});
    }
    for (int i=1;i<=n;i++){
        sort(y[i].begin(),y[i].end());
        for (int j=0;j<y[i].size();j++) E[y[i][j].S]=j+1;
        build(i,y[i].size()+2);
    }
    for (int i=n;i;i--){
        DP[i]=1+get(n+1,n+1)-get(n+1,a[i]);
        DP[i]%=mod;
        DP[i]+=mod;
        DP[i]%=mod;
        add(n+1,a[i],DP[i]);
        if (nxt[i]==i){
            dp[i]=1;
            add(nxt[i],E[i],dp[i]);
        }
        else{
            dp[i]=get(nxt[i],y[nxt[i]].size()+1)-get(nxt[i],E[i]);
            dp[i]%=mod;
            dp[i]+=mod;
            dp[i]%=mod;
            add(nxt[i],E[i],dp[i]);
        }
        //for (int j=i+1;j<=n;j++) if (a[j]>a[i] && nxt[j]==nxt[i]) dp[i]+=dp[j];

    }
    for (int i=1;i<=n;i++){
        ans+=pd[i]*DP[i]%mod;
        ans-=pd[i]*dp[i]%mod;
        ans+=mod;
        ans%=mod;
    }
    cout << ans << endl;


    return 0;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}