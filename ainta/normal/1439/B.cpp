#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<set>
#define pii pair<int,int>
using namespace std;
vector<int>E[101000];
unordered_map<int,int>Map[101000];
int Q[101000], head, tail, vis[101000], Deg[101000];
void Solve(){
    int n, m, K, i, j;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++){
        E[i].clear();
        Deg[i]=0;
        Map[i].clear();
    }
    vector<pii>V;
    for(i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
        Map[a][b]=Map[b][a]=1;
        Deg[a]++,Deg[b]++;
    }
    head=tail=0;
    for(i=1;i<=n;i++){
        vis[i]=0;
        if(Deg[i]<K-1){
            Q[++tail]=i;
            vis[i]=1;
        }
    }
    while(head < tail){
        int x = Q[++head];
        vis[x]=2;
        for(auto &t : E[x]){
            Deg[t]--;
            if(Deg[t]<K-1 && !vis[t]){
                vis[t]=1;
                Q[++tail]=t;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(!vis[i] && Deg[i] == K-1){
            Q[++tail] = i;
            vis[i] = 1;
        }
    }
    int chk=0;
    while(head < tail){
        int x = Q[++head];
        vector<int>Z;
        Z.push_back(x);
        vis[x]=2;
        for(auto &z : E[x]){
            if(vis[z]!=2)Z.push_back(z);
        }
        if(Z.size()==K){
            int ck=0;
            for(i=1;i<Z.size();i++){
                for(j=i+1;j<Z.size();j++){
                    if(!Map[Z[i]].count(Z[j])){
                        ck=1;
                        break;
                    }
                }
                if(ck)break;
            }
            if(!ck){
                printf("%d\n",2);
                for(auto &t : Z)printf("%d ",t);
                puts("");
                chk=1;
                break;
            }
        }
        for(auto &y : E[x]){
            Deg[y]--;
            if(Deg[y]<K && !vis[y]){
                vis[y]=1;
                Q[++tail]=y;
            }
        }
    }
    if(!chk && tail!=n){
        vector<int>Z;
        for(i=1;i<=n;i++)if(!vis[i])Z.push_back(i);
        printf("1 %d\n",Z.size());
        for(auto &t : Z)printf("%d ",t);
        puts("");
    }
    else if(!chk){
        puts("-1");
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}