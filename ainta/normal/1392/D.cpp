#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, D[401000], Res;
char p[401000];
int Do(int b, int e){
    int i;
    for(i=b-1;i<=e;i++)D[i]=1e9;
    D[b-1]=0;
    for(i=b-1;i<=e;i++){
        if(i+2<=e){
            int c=0;
            if(p[i+1]!='R')c++;
            if(p[i+2]!='L')c++;
            D[i+2]=min(D[i+2],D[i]+c);
        }
        if(i+3<=e){
            int c=0;
            if(p[i+1]!='R')c++;
            if(p[i+3]!='L')c++;
            D[i+3]=min(D[i+3],D[i]+c);
        }
        if(i+4<=e){
            int c=0;
            if(p[i+1]!='R')c++;
            if(p[i+2]!='R')c++;
            if(p[i+3]!='L')c++;
            if(p[i+4]!='L')c++;
            D[i+4]=min(D[i+4],D[i]+c);
        }
    }
    return D[e];
}
void Solve(){
    int i;
    scanf("%d",&n);
    scanf("%s",p+1);
    for(i=1;i<=5;i++)p[n+i]=p[i];
    Res=1e9;
    for(i=1;i<=4;i++){
        Res=min(Res,Do(i,i+n-1));
    }
    printf("%d\n",Res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}