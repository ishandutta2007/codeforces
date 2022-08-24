#include<cstdio>
#include<algorithm>
using namespace std;
int n, st, d;
long long X,Y;
char p[101000];
int S[101000];
void Solve(){
    int i;
    scanf("%d%d%d",&n,&st,&d);
    scanf("%s",p+1);
    for(i=n;i>=1;i--){
        if(p[i]=='0')S[i]=1;
        else S[i]=0;
        if(i+d<=n)S[i]+=S[i+d];
    }
    scanf("%lld%lld",&X,&Y);
    long long res=1e18;
    for(i=st;i<=n;i++){
        res=min(res,Y*(i-st) + S[i]*X);
    }
    printf("%lld\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}