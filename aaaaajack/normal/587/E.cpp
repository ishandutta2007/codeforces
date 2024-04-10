#include<cstdio>
#include<cstring>
#define N (1<<18)
using namespace std;
int seg[N<<1][33];
int a[N];
void merge(int *l,int lsz,int *r,int rsz,int *m,int &msz){
	msz=lsz;
	memcpy(m,l,sizeof(int)*msz);
	for(int i=0;i<rsz&&msz<31;i++){
		int tmp=r[i];
		for(int j=0;j<msz;j++){
			if((m[j]&-m[j])&tmp){
				tmp^=m[j];
			}
		}
		if(tmp){
			m[msz]=tmp;
			for(int j=0;j<msz;j++){
				if(m[j]&(tmp&-tmp)) m[j]^=tmp;
			}
			msz++;
		}
	}
}
void build(int u,int l,int r){
	if(l+1==r){
		seg[u][31]=1;
		seg[u][0]=a[l]<<1|1;
		return;
	}
	int m=(l+r)/2;
	build(u<<1,l,m);
	build(u<<1|1,m,r);
	merge(seg[u<<1],seg[u<<1][31],seg[u<<1|1],seg[u<<1|1][31],seg[u],seg[u][31]);
}
inline void xork(int *arr,int& sz,int k){
	arr[0]^=(k<<1);
	for(int i=1;i<sz;i++){
		if(arr[0]&(arr[i]&-arr[i])) arr[0]^=arr[i];
	}
}
void push(int u){
	if(seg[u][32]){
		xork(seg[u<<1],seg[u<<1][31],seg[u][32]);
		xork(seg[u<<1|1],seg[u<<1|1][31],seg[u][32]);
		seg[u<<1][32]^=seg[u][32];
		seg[u<<1|1][32]^=seg[u][32];
		seg[u][32]=0;
	}
}
void qry(int u,int ql,int qr,int l,int r,int *res,int &msz){
	if(l==ql&&r==qr){
		msz=seg[u][31];
		memcpy(res,seg[u],sizeof(int)*msz);
		return;
	}
	push(u);
	int m=(l+r)/2;
	if(m>=qr){
		qry(u<<1,ql,qr,l,m,res,msz);
	}
	else if(m<=ql){
		qry(u<<1|1,ql,qr,m,r,res,msz);
	}
	else{
		int lRes[32],rRes[32],lsz,rsz;
		qry(u<<1,ql,m,l,m,lRes,lsz);
		qry(u<<1|1,m,qr,m,r,rRes,rsz);
		merge(lRes,lsz,rRes,rsz,res,msz);
	}
}
void upd(int u,int ql,int qr,int l,int r,int k){
	if(l==ql&&r==qr){
		xork(seg[u],seg[u][31],k);
		seg[u][32]^=k;
		return;
	}
	push(u);
	int m=(l+r)/2;
	if(m>=qr){
		upd(u<<1,ql,qr,l,m,k);
	}
	else if(m<=ql){
		upd(u<<1|1,ql,qr,m,r,k);
	}
	else{
		upd(u<<1,ql,m,l,m,k);
		upd(u<<1|1,m,qr,m,r,k);
	}
	merge(seg[u<<1],seg[u<<1][31],seg[u<<1|1],seg[u<<1|1][31],seg[u],seg[u][31]);
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	build(1,0,n);
	while(q--){
		int t,l,r,k;
		int res[32],sz;
		scanf("%d%d%d",&t,&l,&r);
		if(t==2){
			qry(1,l-1,r,0,n,res,sz);
			if(res[0]==1) printf("%d\n",1<<sz-1);
			else printf("%d\n",1<<sz);
		}
		else{
			scanf("%d",&k);
			upd(1,l-1,r,0,n,k);
		}
	}
	return 0;
}