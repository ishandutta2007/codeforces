#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define pii pair<int,int>
int n, A, B, w[101000], chk[101000], R[101000], PV[101000], C[101000], Rem[101000];
vector<int>G[101000];
void Solve(){
    int i;
    scanf("%d%d%d",&n,&A,&B);
    for(i=1;i<=n+1;i++){
        G[i].clear();
        chk[i]=R[i]=PV[i]=0;
        C[i]=Rem[i]=0;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        G[w[i]].push_back(i);
    }
    int ttt=-1;
    for(i=1;i<=n+1;i++){
        if(G[i].empty())ttt=i;
    }
    set<pii>Set;
    for(i=1;i<=n+1;i++){
        int t = G[i].size();
        Set.insert({t,i});
    }
    for(i=1;i<=A;i++){
        auto it = Set.end();
        it--;
        pii tp = *it;
        int z = it->second;
        Set.erase(it);
        int u = G[z][PV[z]++];
        chk[u]=1;
        R[u]=z;
        Set.insert({tp.first-1, tp.second});
    }
    for(i=1;i<=n;i++){
        if(!R[i])Rem[w[i]]++;
    }
    int s = B-A;
    for(i=1;i<=n+1;i++){
        int t =min(Rem[i], n-A-Rem[i]);
        C[i]=min(s,t);
        s-=C[i];
    }
    if(s>0){
        puts("NO");
        return;
    }

    Set.clear();

    for(i=1;i<=n+1;i++){
        Set.insert({Rem[i] + C[i],i});
    }

    for(i=1;i<=n;i++){
        if(R[i])continue;
        int ck=0;
        while(!Set.empty()){
            auto it = Set.end();it--;
            if(it->second==w[i]){
                if(it==Set.begin())break;
                it--;
            }
            
            int x = it->second;
            if(!C[x]){
                Set.erase(it);
                continue;
            }
            Set.erase(it);
            C[x]--;
            Set.insert({Rem[x]+C[x],x});
            R[i]=x;
            ck=1;
            break;
        }
        if(!ck){
            R[i] = ttt;
        }
        pii tp = {Rem[w[i]]+C[w[i]], w[i]};
        Rem[w[i]]--;
        if(Set.find(tp)!=Set.end()){
            Set.erase(Set.find(tp));
            tp.first--;
            Set.insert(tp);
        }
    }
    puts("YES");
    for(i=1;i<=n;i++){
        printf("%d ",R[i]);
    }
    puts("");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}