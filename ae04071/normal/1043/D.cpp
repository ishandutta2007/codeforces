#include <bits/stdc++.h>
using namespace std;

int n,m,a[10][100000],cnt[100001],nxt[100001],vis[100001],ind[100001];
vector<int> adj[100001];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(j!=0){
                if(!nxt[a[i][j-1]]) nxt[a[i][j-1]]=a[i][j];
                else if(nxt[a[i][j-1]]!=a[i][j]) cnt[a[i][j-1]]=0;
                cnt[a[i][j-1]]++;
            }
        }
    }

    for(int i=1;i<=n;i++) if(cnt[i]==m)
        ind[nxt[i]]=1;

    long long ans=0;
    for(int i=1;i<=n;i++) if(!vis[i] && !ind[i]){
        vis[i]=1;
        int cur=i,l=1;
        while(cnt[cur]==m){
            l++; cur=nxt[cur]; vis[cur]=1;
        }

        ans+=1ll*l*(l+1)/2;
    }
    printf("%lld\n",ans);

    return 0;
}