#include<bits/stdc++.h>
using namespace std;
int sm[300005*21],ls[300005*21],rs[300005*21];
int tot;
int a[300005],id[300005];
long long f[300005];
void add(int x,int y,int l,int r,int u,int wz){
	if(l==r){
		sm[y]=wz;
		return;
	}
	int mid=(l+r)>>1;
	ls[y]=ls[x],rs[y]=rs[x];
	if(u<=mid)add(ls[x],ls[y]=++tot,l,mid,u,wz);
	else add(rs[x],rs[y]=++tot,mid+1,r,u,wz);
}
int query(int y,int l,int r,int u){
	if(l==r)return sm[y];
	int mid=(l+r)>>1;
	if(u<=mid)return query(ls[y],l,mid,u);
	return query(rs[y],mid+1,r,u);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		tot=0;
		id[n+1]=0,f[n+1]=0;
		for(int i=n;i>=1;--i){
			int wz=query(id[i+1],1,n,a[i]);
			if(wz){
				f[i]=f[wz+1]+1;
				add(id[wz+1],id[i]=++tot,1,n,a[i],i);
			}
			else{
				f[i]=0;
				add(id[n+1],id[i]=++tot,1,n,a[i],i);
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i)ans+=f[i];
		printf("%lld\n",ans);
	}
	return 0;
}