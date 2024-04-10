#include<cstdio>
const int N=300005;
int n,t,a[N],k;
long long ans=0;
// void OR(int *f,int x)
// {
// 	for(int mid=1;(mid<<1)<=n;mid<<=1)
// 	{
// 		int R=mid<<1;
// 		for(int i=0;i<n;i+=R)
// 			for(int j=0;j<mid;j++)
// 				f[i+j+mid]=(f[i+j+mid]+f[i+j]);
// 	}
// }
int main(){
    scanf("%d",&t);
    while(t--){
        ans=k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        long long ans=-1e9;
        for(int i=n-k-5;i<n;i++){
            if(i<0) i=0;
            for(int j=i+1;j<n;j++){
                if(1ll*(i+1)*(j+1)-k*(a[i]|a[j])>ans)
                    ans=1ll*(i+1)*(j+1)-k*(a[i]|a[j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}