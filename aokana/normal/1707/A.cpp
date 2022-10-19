#include<cstdio>
#include<cstring>
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
bool vis[maxn];
inline bool check(int k){
	memset(vis,0,n+1);
	for(int i=1;i<=n;++i)
		if(a[i]<=m)
			vis[i]=true,--k;
	if(k<=0)return true;
	for(int i=n;i;--i){
		if(!vis[i])vis[i]=true,--k;
		if(!k)break;
	}
	for(int i=1,j=m;i<=n;++i)
		if(vis[i]){
			if(j<=0)return false;
			if(a[i]>j)--j;
		}
	return true;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int l=0,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))l=mid+1;
			else r=mid-1;
		}
		check(l-1);
		for(int i=1;i<=n;++i)putchar(vis[i]|48);
		putchar(10);
	}
	return 0;
}