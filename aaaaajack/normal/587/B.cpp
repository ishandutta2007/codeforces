#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1001000
#define Q 1000000007
using namespace std;
int a[N],b[N],sum[2][N],cnt[N];
int main(){
    int n,k,ans=0,u=0,m=0,tmp;
    long long l;
    scanf("%d%I64d%d",&n,&l,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    m=unique(b,b+n)-b;
    for(int i=0;i<n&&i<l;i++){
        cnt[i]=lower_bound(b,b+m,a[i])-b;
        sum[u][cnt[i]]++;
        ans+=((l-1-i)/n+1)%Q;
        ans%=Q;
    }
    for(int i=1;i<m;i++){
        sum[u][i]+=sum[u][i-1];
    }
    for(int i=1;i<k;i++){
        memset(sum[u^1],0,sizeof(int)*m);
        for(int j=0;j<n&&i*n+j<l;j++){
            tmp=sum[u][cnt[j]];
            ans+=((l-1-i*n-j)/n+1)%Q*tmp%Q;
            ans%=Q;
            sum[u^1][cnt[j]]+=tmp;
            sum[u^1][cnt[j]]%=Q;
        }
        u^=1;
        for(int j=1;j<m;j++){
            sum[u][j]+=sum[u][j-1];
            sum[u][j]%=Q;
        }
    }
    printf("%d\n",ans);
    return 0;
}