#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int a[N],b[N],c[N];
long long d[N][20],e[N][20];

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    for(int i=1;i<=n;i++){
        c[i]=b[i]-a[i];
        d[i][0]=d[i-1][0]+c[i];
        e[i][0]=d[i][0];
        for(int j=1;i-(1<<j)>=0;j++){
            d[i][j]=min(d[i][j-1],d[i-(1<<(j-1))][j-1]);
            e[i][j]=max(e[i][j-1],e[i-(1<<(j-1))][j-1]);
        }
    }
    // build(1,n,1);
    int l,r;
    while(q--){
        scanf("%d%d",&l,&r);
        if(d[r][0]!=d[l-1][0])
            {puts("-1"); continue;}
        int k;
        for(k=0;(1<<k)<=(r-l);++k); --k;
        if(min(d[r-1][k],d[l+(1<<k)-1][k])<d[r][0])
            {puts("-1"); continue;}
        printf("%lld\n",max(e[r-1][k],e[l+(1<<k)-1][k])-e[r][0]);
    }
    return 0;
}