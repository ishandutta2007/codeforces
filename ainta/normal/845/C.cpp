#include<cstdio>
#include<algorithm>
using namespace std;
int n, X[401000], S[401000];
struct point{
    int b, e;
}w[201000];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].b,&w[i].e);
        X[i]=w[i].b,X[i+n]=w[i].e;
    }
    sort(X+1,X+n+n+1);
    for(i=1;i<=n;i++){
        w[i].b = lower_bound(X+1,X+n+n+1,w[i].b)-X;
        w[i].e = lower_bound(X+1,X+n+n+1,w[i].e)-X;
        S[w[i].e+1]--;
        S[w[i].b]++;
    }
    for(i=1;i<=n+n;i++){
        S[i]+=S[i-1];
        if(S[i]>2){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}