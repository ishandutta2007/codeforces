#include<bits/stdc++.h>
#define N 200100
using namespace std;
vector<int> pos[N],fac[N];
int a[N],ml[N],mr[N];
int mv[N*4],cov[N*4];
long long sum[N*4];
inline long long qsum(int u,int l,int r){
	if(cov[u]>=0) return 1LL*(r-l)*cov[u];
	return sum[u];
}
inline void pull(int u,int l,int r){
	sum[u]=qsum(u<<1,l,(l+r)/2)+qsum(u<<1|1,(l+r)/2,r);
	mv[u]=max(max(mv[u<<1],cov[u<<1]),max(mv[u<<1|1],cov[u<<1|1]));
}
inline void push(int u,int l,int r){
	if(cov[u]>=0){
		mv[u]=max(mv[u],cov[u]);
		sum[u]=1LL*(r-l)*cov[u];
		cov[u<<1]=cov[u<<1|1]=cov[u];
		cov[u]=-1;
	}
}
void build(int u,int l,int r){
	if(l+1==r){
		cov[u]=mv[u]=sum[u]=ml[l];
		return;
	}
	build(u<<1,l,(l+r)/2);
	build(u<<1|1,(l+r)/2,r);
	cov[u]=-1;
	sum[u]=sum[u<<1]+sum[u<<1|1];
	mv[u]=max(mv[u<<1],mv[u<<1|1]);
}	
void upd(int u,int l,int r,int ql,int c){
	if(l==ql&&c>max(mv[u],cov[u])){
		cov[u]=c;
		return;
	}
	if(l==ql&&r==ql+1) return;
	int m=(l+r)/2;
	push(u,l,r);
	if(c>mv[u<<1]) upd(u<<1|1,m,r,max(ql,m),c);
	if(ql<m) upd(u<<1,l,m,ql,c);
	pull(u,l,r);
}
long long qry(int u,int l,int r,int qr){
	if(r==qr){
		return qsum(u,l,r);
	}
	push(u,l,r);
	int m=(l+r)/2;
	if(qr<=m) return qry(u<<1,l,m,qr);
	else{
		return qsum(u<<1,l,m)+qry(u<<1|1,m,r,qr);
	}
}
int main(){
	int n,l,r;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				pos[j].push_back(i);
				fac[i].push_back(j);
				if(a[i]/j!=j){
					pos[a[i]/j].push_back(i);
					fac[i].push_back(a[i]/j);
				}
			}
		}
		sort(fac[i].begin(),fac[i].end());
	}
	for(int i=1;i<N;i++){
		if(pos[i].size()>=2){
			int sz=pos[i].size();
			ml[pos[i][1]]=max(ml[pos[i][1]],i);
			mr[pos[i][sz-2]]=max(mr[pos[i][sz-2]],i);
		}
	}
	for(int i=1;i<n;i++){
		ml[i]=max(ml[i-1],ml[i]);
	}
	for(int i=n-2;i>=0;i--){
		mr[i]=max(mr[i],mr[i+1]);
	}
	build(1,0,n);
	ans+=qry(1,0,n,n-1);
	for(int i=n-1;i>0;i--){
		upd(1,0,n,0,mr[i]);
		for(int j=0;j<fac[i].size();j++){
			upd(1,0,n,pos[fac[i][j]][0],fac[i][j]);
		}
		ans+=mr[i]+qry(1,0,n,i-1);
	}
	printf("%I64d\n",ans);
	return 0;
}