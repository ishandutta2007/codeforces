#include <bits/stdc++.h>
typedef long long int ll;
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
const int N=1e5+100,M=14,K=1e3+10;
int C[N][M],ts=0,F[N];
int ras[N];
bool vis[N];
vector <int> g[N];
ll val[N];
void add(string x,ll id,ll t){
    int now=0;
    for (char ch : x){
        if (!C[now][ch-'a']){
            C[now][ch-'a']=++ts;
        }
        now=C[now][ch-'a'];
    }
    ras[id]=now;
    val[now]+=t;
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
void dfs(ll v){
    for (auto u : g[v]){
        val[u]+=val[v];
        dfs(u);
    }
}
ll W[M+1][K];
int nxt[M+1][K];
ll dp[2][(1<<M)][1003];

int32_t main(){
    sync;
    int n;
    cin >> n;

   // return 0;
    for (int i=1;i<=n;i++){
        string s;
        ll c;
        cin >> s >> c;
        add(s,i,c);
    }
    build_aho();
   // cout << " cf" << val[ras[3]] << endl;
    dfs(0);
    for (int i=1;i<=ts;i++){
   //     cout << val[i] << endl;
    }
    string s;
    cin >> s;
     int cnt=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='?'){
            cnt++;
            for (int j=0;j<=ts;j++){
                nxt[cnt][j]=j;
            }
            continue;
        }
        for (int j=0;j<=ts;j++){
            ll nod=nxt[cnt][j];
            nod=C[nod][s[i]-'a'];
            nxt[cnt][j]=nod;
            W[cnt][j]+=val[nod];
        }
    }
    memset(dp,-31,sizeof dp);
    dp[0][0][0]=0;
    for (int i=0;i<cnt;i++){
        memset(dp[(i+1)%2],-31,sizeof dp[(i+1)%2]);
        for (int j=0;j<(1<<M);j++){
            if (__builtin_popcount(j)!=i) continue;
            for (int p=0;p<=ts;p++){
                for (int k=0;k<M;k++){
                    if (((1<<k) & j)) continue;
                    ll nod=nxt[i][p];
                    ll arz=W[i][p];
                    nod=C[nod][k];
                    arz+=val[nod];
                    dp[(i+1)%2][j+(1<<k)][nod]=max(dp[(i+1)%2][j+(1<<k)][nod],dp[i%2][j][p]+arz);
                }
            }
        }

    }
    ll ans=-(ll)1e15;
    for (int i=0;i<=ts;i++){
        for (int j=0;j<(1<<M);j++){
            ans=max(ans,dp[cnt%2][j][i]+W[cnt][i]);
        }
    }
    cout << ans << endl;

}