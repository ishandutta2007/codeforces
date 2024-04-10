#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,sx,a[300039],pr[1000039],fs[1000039],flag[1000039],sum[1200039],ph,s[1000039],ans,tot,pus,now,last;
long long f[1200039];
inline void jianshu(int l,int r,int now){
	if(l==r){
		f[now]=a[l];
		if(a[l]==1||a[l]==2)sum[now]=1;
		return ;
	}
	int m=(l+r)>>1;
	jianshu(l,m,now<<1);
	jianshu(m+1,r,now<<1|1);
	sum[now]=sum[now<<1]&sum[now<<1|1];
	f[now]=f[now<<1]+f[now<<1|1];
}
inline void get(int l,int r,int now){
	if(l==r){
		f[now]=s[f[now]];
		if(f[now]==1||f[now]==2)sum[now]=1;
		return ;
	}
	int m=(l+r)>>1;
	if(x<=m&&!sum[now<<1]) get(l,m,now<<1);
	if(y>m&&!sum[now<<1|1]) get(m+1,r,now<<1|1);
	sum[now]=sum[now<<1]&sum[now<<1|1]; 
	f[now]=f[now<<1]+f[now<<1|1];
}
inline long long find(int l,int r,int now){
	if(x<=l&&r<=y) return f[now];
	int m=(l+r)>>1;
	long long fs=0;
	if(x<=m) fs+=find(l,m,now<<1);
	if(y>m) fs+=find(m+1,r,now<<1|1);
	return fs;
}
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),ans=max(ans,a[i]);
	for(i=2;i<=ans;i++){
		if(!fs[i]) pr[++ph]=i,flag[i]=i;
		for(j=1;j<=ph&&pr[j]*i<=1e6;j++){
			fs[pr[j]*i]=1;
			flag[pr[j]*i]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
	for(i=1;i<=ans;i++){
		now=i;tot=0;last=0;s[i]=1;
		while(now!=1){
			if(last!=flag[now]) s[i]*=tot+1,last=flag[now],tot=0;
			tot++;now/=flag[now];
		}
		s[i]*=tot+1;
		//printf("%d ",flag[i]);
	}
	//printf("\n");
	jianshu(1,n,1);
	for(i=1;i<=m;i++){
		scanf("%d",&sx);
		if(sx==1){
			scanf("%d%d",&x,&y);
			get(1,n,1);
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",find(1,n,1));
		}
	}
}