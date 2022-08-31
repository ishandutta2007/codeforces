#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
int n, w[501000], LL[501000], RR[501000];
int OK[501000], ML[501000], MR[501000];
int TR[501000], TL[501000], SL[501000], SR[501000];
vector<int>G[501000], T, OO[501000];
struct AA{
    int b, e;
}U[501000];
bool Pos(int K){
    int i, m = T.size();
    for(i=0;i<K;i++){
        U[i+1] = {T[i],T[m-K+i]};
    }
    int c=0;
    for(i=1;i<=n;i++){
        if(w[i]==0)c++;
        else LL[i]=c;
    }
    c=0;
    for(i=n;i>=1;i--){
        if(w[i]==0)c++;
        else RR[i]=c;
    }
    for(i=1;i<=n;i++)OK[i]=ML[i]=MR[i]=0;
    for(i=1;i<=n;i++){
        if(w[i]){
            int l = min(LL[i],K);
            int r = min(RR[i],K);
            if(l==K && r==K)OK[w[i]]=1;
            else if(l==K) MR[w[i]]=max(MR[w[i]],r);
            else ML[w[i]] = max(ML[w[i]], l);
        }
    }
    int need = K;
    for(i=1;i<=K;i++)TR[i]=TL[i]=0;
    vector<AA>Z;
    for(i=0;i<=K+K;i++)OO[i].clear();
    for(i=1;i<=n;i++){
        if(OK[i]){
            need--;
            continue;
        }
        if(!ML[i] && !MR[i])continue;
        if(!ML[i]){
            OO[K+1].push_back(K+MR[i]);
        }
        else if(!MR[i]){
            OO[K-ML[i]+1].push_back(K);
        }
        else{
            OO[K-ML[i]+1].push_back(K+MR[i]);
        }
    }
    if(need<=0)return true;
    priority_queue<int>PQ;
    for(i=1;i<=K+K;i++){
        for(auto &t : OO[i])PQ.push(-t);
        while(!PQ.empty()){
            int x = -PQ.top();
            PQ.pop();
            if(x<i)continue;
            need--;
            if(need<=0)return true;
            break;
        }
    }
    return false;
}
void Solve(){
    int i;
    scanf("%d",&n);
    T.clear();
    for(i=1;i<=n;i++)G[i].clear();
    int e=0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]==0)T.push_back(i);
        else{
            if(G[w[i]].empty())e++;
            G[w[i]].push_back(i);
        }
    }
    e=min(e,(int)T.size()/2);
    int b = 1, r = 0, mid;
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid)){
            r=mid;
            b=mid+1;
        }
        else e=mid-1;
    }
    printf("%d\n",r);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}