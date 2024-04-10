#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const double eps=1e-8;
const int mod=1e9+7;
const int N=1e5+10;
const int inf=1e9;
int n,m;
vector<int>g[20],v;
int a[20],c[20],d[20],dp[20][20][1<<18],f[20][20][1<<18],bit[20];
int main(){
    cin>>n>>m;
    for(int i=1,x,y,w;i<=m;i++){
        cin>>x>>y>>w;
        --x;--y;
        c[x]+=w;
        c[y]-=w;
        g[x].pb(y);
        ++d[y];
        bit[x]|=1<<y;
    }
    queue<int>q;
    for(int i=0;i<n;i++) if(d[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        v.pb(u);
        for(int x:g[u]){
            if(--d[x]==0) q.push(x);
        }
    }
    memset(dp,0x3f3f3f,sizeof dp);
    dp[0][0][0]=0;
    for(int i=0;i<n;i++) for(int j=0;j<=n;j++) for(int k=0;k<(1<<n);k++){
        if(j==n){
            if(dp[i+1][0][k]>dp[i][j][k]){
                dp[i+1][0][k]=dp[i][j][k];
                f[i+1][0][k]=-1;
            }
            continue;
        }
        int x=v[j];
        if(dp[i][j+1][k]>dp[i][j][k]){
            dp[i][j+1][k]=dp[i][j][k];
            f[i][j+1][k]=-1;
        }
        if(!(k>>x&1)&&(bit[x]&k)==bit[x]){
            int nk=k^(1<<x);
            if(dp[i][j+1][nk]>dp[i][j][k]+c[x]*i){
                dp[i][j+1][nk]=dp[i][j][k]+c[x]*i;
                f[i][j+1][nk]=k;
            }
        }
    }
    int x=1,y=0,s=(1<<n)-1;
    for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) if(dp[i][j][s]<dp[x][y][s]) x=i,y=j;
    while(x||y||s){
        if(f[x][y][s]==-1){
            if(y==0){
                x--;
                y=n;
            }else y--;
        }else{
            int ns=f[x][y][s];
            int k=ns^s;
            for(int i=0;i<n;i++) if(k>>i&1){
                a[i]=x;
            }
            s=ns;
            y--;
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}