#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

int n,k,arr[200001];
int da[200001],dac[200001],dmc[200001][2];
vector<int> adj[200001];

int T,ret;
void dfs(int cur,int p) {
    da[cur]=dac[cur]=dmc[cur][0]=dmc[cur][1]=0;
    da[cur]=1;
    for(auto &it:adj[cur]) if(it!=p) {
        dfs(it,cur);
        da[cur] &= da[it];
        if(da[it]) {
            dac[cur] += dac[it];
        } else {
            for(int i=0;i<2;i++) if(dmc[cur][i]<dmc[it][0]) {
                for(int j=i+1;j<2;j++) dmc[cur][j]=dmc[cur][j-1];
                dmc[cur][i]=dmc[it][0];
                break;
            }
        }
    }
    
    if(arr[cur]<T) da[cur]=dac[cur]=dmc[cur][0]=dmc[cur][1]=0;
    else {
        if(da[cur]) dac[cur]++;
        else {
            for(int i=0;i<2;i++) dmc[cur][i]+=dac[cur]+1;
            dac[cur]=0;
        }
    }
}
void get(int cur,int p,int a,int ac,int mc) {
    if(arr[cur]>=T) {
        if(a && da[cur]) ret = max(ret,dac[cur]+ac);
        else if(a) ret = max(ret,max(ac+dmc[cur][0],mc+1));
        else if(da[cur]) ret = max(ret,max(dac[cur]+mc,dmc[cur][0]));
        else ret = max(ret, max(dmc[cur][0],mc+1));
    }
    
    int f=!a,mc2=0;
    for(auto &it:adj[cur]) if(it!=p){
        if(da[it]) ac+=dac[it];
        else {
            f++;
            if(mc < dmc[it][0]) {
                mc2=mc; mc=dmc[it][0];
            } else if(mc2<dmc[it][0]) mc2=dmc[it][0];
        }
    }
    for(auto &it:adj[cur]) if(it!=p) {
        if(arr[cur]<T) {
            get(it,cur,0,0,0);
        } else if(f==0) {
            get(it,cur,1,ac-dac[it]+1,0);
        }else {
            if(f-(!da[it])==0) {
                get(it,cur,1,ac+1,0);
            } else {
                if(dmc[it][0] == mc) get(it,cur,0,0,mc2+ac-dac[it]+1);
                else get(it,cur,0,0,mc+ac-dac[it]+1);
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int lo=0,up=1e6+1;
    while(up-lo>1) {
        T=(lo+up)>>1;
        dfs(1,0);
        ret=0;
        get(1,0,1,0,0);
        if(ret>=k) lo=T;
        else up=T;
    }
    printf("%d\n",lo);
    return 0;
}