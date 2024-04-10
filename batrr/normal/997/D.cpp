#include <bits/stdc++.h>
/*
#pragma GCC optimize("Ofast")
  */
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=4001,mod=998244353;
vector<int>g[maxn];
int n,m,k,c[80][80];
int sz[maxn],used[maxn];
int dp1[maxn][80],dp2[maxn][80];
int ANS,ans[80],ans1[80],ans2[80];
void add(int &a, int b){
    a+=b;
    if(a>=mod)
        a-=mod;
}
void dfs(int v,int p){
    sz[v]=1;
    for(auto to:g[v])
        if(!used[to] && to!=p){
            dfs(to,v);
            sz[v]+=sz[to];
        }
}
int getctr(int v,int p,int SZ){
    for(auto to:g[v])
        if(!used[to] && to!=p && sz[to]>SZ/2)
            return getctr(to,v,SZ);
    return v;
}           
void calc_dp(int v,int p,int len,int ban){
    for(auto to:g[v])
        if(!used[to]){
            if(to!=p)
                calc_dp(to,v,len,ban);
            if(to!=ban)
                add(dp1[to][len],dp1[v][len-1]);
            add(dp2[to][len],dp2[v][len-1]);
        }    
}

void calc_ans(int v,int p){
    for(int i=0;i<=k;i++)
        for(int j=0;j+i<=k;j++)
            add(ans[i+j],1ll*dp1[v][i]*dp2[v][j]%mod);
    for(auto to:g[v])
        if(!used[to] && to!=p)
            calc_ans(to,v);
}

void solve(int v){
    // get centroid
    dfs(v,v);
    int ctr=getctr(v,v,sz[v]);
    // calc ans on cur comp
    /*
    v1->v2->v3...->centroid->...->centroid->...->centroid->...->v1
    v1->first_centroid->v1                              
    dp1[v][len]-paths from v to centroid - count centroid = 1
    dp2[v][len]-paths from v to centroid - count centroid >=1
    */
    // calc dp
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp1[i][j]=dp2[i][j]=0;
    dp1[ctr][0]=1;
    dp2[ctr][0]=1;
    for(int len=1;len<=k;len++)
        calc_dp(ctr,ctr,len,ctr);
    //calc ans
        /*
    for(int v=1;v<=n;v++)
        for(int len=0;len<=k;len++)
            dp2[v][len]=(dp2[v][len]-dp1[v][len]+mod)%mod;
    */
    /*
    for(int v=1;v<=n;v++)
        for(int i=0;i<=k;i++){
            if(v==ctr){
                add(ans[i],dp2[v][i]);
                continue;
            }
            for(int j=0;j+i<=k;j++)
                add(ans[i+j],dp1[v][i]*dp2[v][j]%mod);    
        }
    */
    calc_ans(ctr,ctr);
    /*
    cout<<ctr<<" "<<ans[2]<<endl;
    for(int i=1;i<=n;i++)
        cout<<dp2[i][1]<<" "<<dp2[i][2]<<endl;
    */
    // delete centroid , solve other omp
    used[ctr]=1;
    for(auto to:g[ctr])
        if(!used[to])
            solve(to);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    for(int i=0;i<80;i++)
        c[0][i]=1;
    for(int i=1;i<80;i++)
        for(int j=1;j<=i;j++)
            c[j][i]=(c[j-1][i-1]+c[j][i-1])%mod;
    scanf("%d%d%d",&n,&m,&k);
    if(k&1)
        cout<<0,exit(0);
    // solve first tree
    for(int i=1;i<n;i++){
        int v,u;
        scanf("%d%d",&v,&u);
        g[v].pb(u);
        g[u].pb(v);
    }
    solve(1);
    for(int i=0;i<=k;i++){
       // cout<<ans[i]<<" ";
        ans1[i]=ans[i];
        ans[i]=0;
    }
    //cout<<endl;
    n=m;
    for(int i=0;i<maxn;i++){
        used[i]=0;
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        int v,u;
        scanf("%d%d",&v,&u);
        g[v].pb(u);
        g[u].pb(v);
    }         
    solve(1);
    for(int i=0;i<=k;i++){
     //   cout<<ans[i]<<" ";
        ans2[i]=ans[i];
        ans[i]=0;
    }
    
    for(int i=0;i<=k;i++)
        add(ANS,1ll*ans1[i]*ans2[k-i]%mod*c[i][k]%mod);
    cout<<ANS;
}