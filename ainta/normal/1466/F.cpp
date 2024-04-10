#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using pii = pair<int,int>;
int n, m, chk[501000], Q[501000], vis[501000], NN[501000];

int UF[501000], UD[501000];
vector<int>G[501000], Ans;
int dd=0;
int Find(int a){
    dd^=UD[a];
    if(a==UF[a])return a;
    return Find(UF[a]);
}
void Merge(int a, int b, int num){
    int dd1, dd2;
    dd=0;
    int x = Find(a);
    dd1=dd;
    dd=0;
    int y = Find(b);
    dd2=dd;

    if(chk[x]!=chk[y]){
        if(!chk[x]){
        }
    }
    if(x==y){
        //printf("%d %d %d %d %d %d\n",a,x,b,y,dd1,dd2);
        /*printf("%d %d\n",dd1,dd2);
        if(!chk[x] && (dd1^dd2)==0){
            Ans.push_back(num);
            for(auto &t : G[x])chk[t]=1;
        }*/
        return;
    }
    if(!chk[x]||!chk[y])Ans.push_back(num);
    if(G[x].size()<G[y].size())swap(x,y);
    if(chk[x]!=chk[y]){
        if(chk[x]){
            for(auto &t : G[y])chk[t]=1;
        }
        else{
            for(auto &t : G[x])chk[t]=1;
        }
    }
    for(auto &t : G[y])G[x].push_back(t);
    UF[y]=x;
    UD[y]=((dd1^dd2)^1);
}
void Solve(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        chk[i]=0;
        UF[i]=i,UD[i]=0;
        G[i].clear();
        G[i].push_back(i);
    }
    Ans.clear();
    for(i=1;i<=n;i++){
        int K, a, b;
        scanf("%d",&K);
        if(K==1){
            scanf("%d",&a);
            if(!chk[a]){
                int t = Find(a);
                for(auto &u : G[t]){
                    chk[u]=1;
                }
                Ans.push_back(i);
            }
            continue;
        }
        else{
            scanf("%d%d",&a,&b);
            Merge(a,b,i);
        }
    }
    int res=1;
    for(i=0;i<Ans.size();i++)res=res*2%1000000007;
    sort(Ans.begin(),Ans.end());
    printf("%d %d\n",res,Ans.size());
    for(auto &t : Ans)printf("%d ",t);
    puts("");
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}