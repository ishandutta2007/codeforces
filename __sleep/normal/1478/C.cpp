#include<cstdio>
#include<algorithm>
int t,n,flag;
long long a[200005],b[200005];
int main(){
    scanf("%d",&t);
    while(t--){
        flag=1;
        scanf("%d",&n);
        for(int i=0;i<2*n;i++)
            scanf("%lld",a+i);
        std::sort(a,a+n*2);
        b[2*n+1]=b[2*n-1]=0; a[2*n+1]=2e18;
        for(int i=2*n-1;i>=0&&flag;i-=2){
            if(a[i]!=a[i-1])
                flag=0;
            a[i]-=b[i+2];
            if(a[i]%(i+1)!=0)
                flag=0;
            a[i]=a[i]/(i+1);
            b[i]=2*a[i]+b[i+2];
            if(a[i]>=a[i+2]) flag=0;
            if(a[i]<=0) flag=0;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}

//20 20 24 24 28 28 40 40
//40 40 48 48 56 56 80 80
//0  0  4 -4 6 -6 10 -10