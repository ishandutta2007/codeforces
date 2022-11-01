#include <cstdio>
int a[300001],b[300001];
long long c[2][2000000];
int main(){
    int n;
    scanf("%d",&n);
    b[0]=0;
    c[0][0]++;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1]^a[i];
        c[i&1][b[i]]++;
    }
    /*
    for(int i=0;i<n;i++) printf("%d ",b[i]);
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d %d\n",c[0][i],c[1][i]);
    }
    */
    long long ans=0LL;
    for(int i=0;i<2000000;i++){
        for(int j=0;j<2;j++){
            ans+=c[j][i]*(c[j][i]-1)/2;
        }
    }
    printf("%lld",ans);
}