#include<cstdio>
using namespace std;
int n,m,k,x,y,zs,head,a[100039],f1[400039][25],f2[400039][25],sum[400039][25],z[25],ans,tot,pus;
inline void hebing(int l,int r,int now){for(int i=0;i<=21;i++) f1[now][i]=f1[now<<1][i]+f1[now<<1|1][i],f2[now][i]=f2[now<<1][i]+f2[now<<1|1][i];}
inline void swap(int &x,int &y){x^=y;y^=x;x^=y;}
inline void push(int l,int r,int now){
	for(int i=0;i<=21;i++){
		sum[now<<1][i]^=sum[now][i];sum[now<<1|1][i]^=sum[now][i];
		if(sum[now][i]) swap(f1[now<<1][i],f2[now<<1][i]),swap(f1[now<<1|1][i],f2[now<<1|1][i]);
		sum[now][i]=0;
	}
} 
inline void jianshu(int l,int r,int now){
	if(l==r){
		for(int i=0;i<=21;i++){
			if(a[l]&(1<<i)) f1[now][i]=1;
			else f2[now][i]=1;
		}
		return ;
	}
	int m=(l+r)>>1;
	jianshu(l,m,now<<1);
	jianshu(m+1,r,now<<1|1);
	hebing(l,r,now);
}
inline void get(int l,int r,int now){
	if(x<=l&&r<=y){
		for(int i=0;i<=21;i++){
			sum[now][i]^=z[i];
			if(z[i]) swap(f1[now][i],f2[now][i]);
		}
		return ;
	}
	push(l,r,now);
	int m=(l+r)>>1;
	if(x<=m) get(l,m,now<<1);
	if(y>m) get(m+1,r,now<<1|1);
	hebing(l,r,now);
}
inline long long find(int l,int r,int now){
	if(x<=l&&r<=y){
		long long ans=0;
		for(int i=0;i<=21;i++) ans+=(1ll<<i)*f1[now][i];
		return ans;
	}
	long long ans=0;
	int m=(l+r)>>1;
	push(l,r,now);
	if(x<=m) ans+=find(l,m,now<<1);
	if(y>m) ans+=find(m+1,r,now<<1|1);
	return ans;
}
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	jianshu(1,n,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d",&x,&y);
			printf("%lld\n",find(1,n,1));
		}
		else{
			scanf("%d%d%d",&x,&y,&zs);
			for(j=0;j<=21;j++) z[j]=zs&(1<<j);
			get(1,n,1);
		}
	}
}