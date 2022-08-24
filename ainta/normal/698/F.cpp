#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 1010000
using namespace std;
vector<int>E[N_];
bool chk[N_];
int n, Num[N_], w[N_], p[N_], cnt, C[N_], G[N_];
int CC[N_];
long long res = 1, Mod = 1000000007;
int Calc(int a){
    if(a==1)return 1;
    return n/a;
}
void Make(int a, int b){
    int i;
    if(E[a].size() != E[b].size()){
        res = 0;
        return;
    }
    for(i=0;i<E[a].size();i++){
        int t1 = E[a][i], t2 = E[b][i];
        if(Calc(t1)!=Calc(t2) || (Num[t2] && Num[t2]!=t1)){
            res = 0;
            return;
        }
        Num[t2] = t1;
    }
}
int main(){
    int i, j;
    scanf("%d",&n);
    p[++cnt] = 1;
    for(i=1;i<=n;i++)G[i]=1;
    for(i=2;i<=n;i++){
        if(!chk[i]){
            for(j=i;j<=n;j+=i){
                E[j].push_back(i);
                chk[j]=true;
                G[j]*=i;
            }
            p[++cnt] = i;
        }
    }
    E[1].push_back(1);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]){
            Make(i,w[i]);
        }
    }
    for(i=1;i<=n;i++)chk[i]=false;
    for(i=1;i<=n;i++){
        if(Num[i]&&chk[Num[i]]){
            res=0;
        }
        chk[Num[i]]=true;
    }
    for(i=1;i<=cnt;i++){
        if(!Num[p[i]]){
            C[Calc(p[i])]++;
            res=res*C[Calc(p[i])]%Mod;
        }
    }
    for(i=1;i<=n;i++){
        if(!w[i]){
            CC[G[i]]++;
            res=res*CC[G[i]]%Mod;
        }
    }
    printf("%lld\n",res);
}