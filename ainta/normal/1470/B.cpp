#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n, CK[1010000], G[1001000], C[1010000];
int w[301000];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        C[G[w[i]]]++;
       // printf("%d\n",G[w[i]]);
    }
    int Q;
    scanf("%d",&Q);
    int a0=0,a1=0;
    set<int>Set;
    Set.insert(1);
    for(i=1;i<=n;i++){
        a0=max(a0, C[G[w[i]]]);
        if(C[G[w[i]]]%2==0){
            Set.insert(G[w[i]]);
        }
    }
    for(auto &t : Set){
        a1 += C[t];
    }
    a1=max(a1,a0);
    while(Q--){
        long long a;
        scanf("%lld",&a);
        if(!a)printf("%d\n",a0);
        else printf("%d\n",a1);
    }
    for(i=1;i<=n;i++){
        C[G[w[i]]]=0;
    }
}
void init(){
    int i, j;
    for(i=1;i<=1000000;i++){
        G[i]=1;
    }
    for(i=2;i<=1000000;i++){
        if(CK[i])continue;
        for(j=i;j<=1000000;j+=i){
            CK[j]=1;
            int t = j, c= 0;
            while(t%i==0)t/=i,c++;
            if(c&1)G[j]*=i;
        }
    }
}
int main(){
    int TC;
    init();
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}