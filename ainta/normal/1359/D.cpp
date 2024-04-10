#include<cstdio>
#include<algorithm>
#define SZ 131072
using namespace std;
int n, w[101000], R[101000][61], S[101000], IT[SZ+SZ], Res;
void Put(int a, int b){
    a+=SZ;
    IT[a]=b;
    while(a!=1){
        a>>=1;
        IT[a]=max(IT[a*2],IT[a*2+1]);
    }
}
int Max(int b, int e){
    int r=-1e9;
    b+=SZ,e+=SZ;
    while(b<=e){
        r=max(r,max(IT[b],IT[e]));
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        S[i]=S[i-1]+w[i];
        Put(i,S[i]);
    }
    for(i=0;i<=60;i++)R[n+1][i]=n+1;
    for(i=n;i>=1;i--){
        for(j=-30;j<=30;j++){
            if(w[i]<=j)R[i][j+30]=R[i+1][j+30];
            else R[i][j+30]=i;
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=60;j++){
            if(R[i][j]==i)continue;
            int t = R[i][j];
            Res=max(Res,Max(i,t-1) - S[i-1]-(j-30));
        }
    }
    printf("%d\n",Res);
}