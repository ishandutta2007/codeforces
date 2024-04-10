#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
long long Odd[101000], Even[101000], Mod = 1000000007;
int n;
void DFS(int a){
    int i, x, j;
    long long rO=1, rE=0, tO, tE, rr[4], trr[4];
    if(!E[a].size()){
        Odd[a]=1;
        return;
    }
    for(i=0;i<4;i++)rr[i]=0;
    rr[0]=rr[2]=1;
    for(i=0;i<E[a].size();i++){
        x=E[a][i];
        DFS(x);
        tO=rO,tE=rE;
        for(j=0;j<4;j++)trr[j]=rr[j];
        rO=(tO*(Even[x]+1)+tE*Odd[x])%Mod;
        rE=(tE*(Even[x]+1)+tO*Odd[x])%Mod;
        rr[0]=(trr[1]*Odd[x]+trr[0])%Mod;
        rr[1]=(trr[0]*Odd[x]+trr[1])%Mod;
        rr[2]=(trr[2]*Even[x]+trr[2])%Mod;
        rr[3]=(trr[3]*Even[x]+trr[3])%Mod;
    }
    rO=rO*2%Mod,rE=rE*2%Mod;
    rO = (rO-rr[2]+Mod*2)%Mod;
    rE = (rE-rr[1]-rr[3]+Mod*2)%Mod;
    Odd[a]=rO,Even[a]=rE;
}
int main(){
    int i, a;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        E[a].push_back(i);
    }
    DFS(1);
    printf("%lld\n",(Odd[1]+Even[1])%Mod);
}