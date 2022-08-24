#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 501000
#define M_ 10100000
using namespace std;
int n, res, PP[M_], w[N_], Z[M_], M = 10000000, RZ[N_];
int C[M_], sz, CK[M_], po[N_], Mod = 1000000007;
long long sum;
vector<int>G[N_], T;
void Add(int pv, int x, int ck){
    if(pv==sz){
        C[x]++;
        CK[x]=ck;
        return;
    }
    Add(pv+1,x,ck);
    Add(pv+1,x*T[pv],!ck);
}

void Calc(int pv, int x, int ck){
    if(pv==sz){
        if(x==1)return;
        if(ck){
            sum += po[C[x]]-1;
        }
        else{
            sum -= po[C[x]]-1;
        }
        return;
    }
    Calc(pv+1,x,ck);
    Calc(pv+1,x*T[pv],!ck);
}
int main(){
    int i, j;
    scanf("%d",&n);
    po[0]=1;
    for(i=1;i<=n;i++)po[i]=po[i-1]*2%Mod;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Z[w[i]]=i;
    }
    for(i=1;i<=n;i++)RZ[i]=Z[w[i]];
    for(i=2;i<=M;i++){
        if(PP[i])continue;
        for(j=i;j<=M;j+=i){
            PP[j]=1;
            if(Z[j])G[Z[j]].push_back(i);
        }
    }
    for(i=1;i<=n;i++){
        int x = Z[w[i]];
        T = G[x];
        sz=T.size();
        Add(0,1,0);
    }
    long long s=0;
    for(i=2;i<=M;i++){
        if(C[i]){
            if(CK[i])s+=po[C[i]]-1;
            else s-=po[C[i]]-1;
        }
    }
    s%=Mod;
    long long res=0;
    for(i=1;i<=n;i++){
        int x = Z[w[i]];
        T = G[x];
        sz = T.size();
        sum = 0;
        Calc(0,1,0);
        sum%=Mod;
        //printf("%lld\n",s-sum);
        res += s-sum;
    }
    res=(res%Mod+Mod)%Mod;
    printf("%lld\n",res);

}