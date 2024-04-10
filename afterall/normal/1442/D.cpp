#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e3+100;
ll dp[N*4][N];
ll val[N][N];
bool vis[N*4][N];
ll sz[N];
    ll n,k;
vector <int> seg[N*4];
void add(ll nod,ll l,ll r,ll L,ll R,ll valu){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].pb(valu);
        return ;
    }
    ll mid=(r+l)/2;
    add(nod*2,l,mid,L,R,valu);
    add(nod*2+1,mid,r,L,R,valu);
}
ll ans=0;
void dfs(ll nod,ll l,ll r,ll p){
    for (int i=0;i<N;i++) dp[nod][i]=dp[p][i],vis[nod][i]=vis[p][i];
    for (auto u : seg[nod]){
        if (vis[nod][u]) cout << 1/0;
        for (int i=k;i;i--){
            if (i>=sz[u]){
                dp[nod][i]=max(dp[nod][i],dp[nod][i-sz[u]]+val[u][sz[u]]);
            }
        }
        vis[nod][u]=1;

    }
    if (r-l==1){
        if (vis[nod][l]) cout << 1/0;
        for (int i=0;i<=min(k,sz[l]);i++){
            ans=max(ans,val[l][i]+dp[nod][k-i]);
        }
        return ;
    }
    ll mid=(r+l)/2;
    dfs(nod*2,l,mid,nod);
    dfs(nod*2+1,mid,r,nod);
}
int32_t main(){
    sync;
cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> sz[i];
        for (int j=1;j<=sz[i];j++){
            if (j>3e3){
                ll x;
                cin >> x;
                continue;
            }
            cin >> val[i][j];
            val[i][j]+=val[i][j-1];
        }
        add(1,1,n+1,1,i,i);
        add(1,1,n+1,i+1,n+1,i);
    }

    dfs(1,1,n+1,0);
    cout << ans << endl;
}