#include<cstdio>
#include<algorithm>
int a[100001],b[100001],c[200002];
int n,y,m,i,j,k,ans;
using namespace std;

#include<ctime>
void sleep(double seconds)
{
    double start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < seconds){
        /// wait
    }
}

int main() {
    sleep(1.5);
	scanf("%d%d",&n,&y);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d%d",&m,&y);
    for (i=1;i<=m;i++) scanf("%d",&b[i]);
    ans=2;c[n+m+1]=0x3f3f3f3f;
    for (k=1;k<=1000000000;k<<=1){
        for (i=1;i<=n;i++) c[i]=a[i]%(k*2);
        for (i=1;i<=m;i++) c[i+n]=(b[i]+k)%(k*2);
        sort(c+1,c+n+m+1);
        for (i=1,j=1;i<=n+m;i++) 
            if (c[i]!=c[i+1]) ans=max(ans,i-j+1),j=i+1;
    }
    printf("%d",ans);
    return 0;
}