#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct T{
	int s[N<<2];
	int u,v;
	bool w,t[N<<2],f[N<<2];
	void upd(int k,int l,int r){
		if(u<=l&&r<=v){
			s[k]=w?(r-l+1):0,t[k]=w,f[k]=1;
			return; 
		}
		int m=l+r>>1,a=k<<1,b=a|1;
		if(f[k]){
			s[a]=t[k]?(m-l+1):0,t[a]=t[k],f[a]=1;
			s[b]=t[k]?(r-m):0,t[b]=t[k],f[b]=1;
			f[k]=0;
		}
		if(u<=m)upd(a,l,m);
		if(m<v)upd(b,m+1,r);
		s[k]=s[a]+s[b];
	}
	int qry(int k,int l,int r){
		if(u<=l&&r<=v)return s[k];
		int m=l+r>>1,a=k<<1,b=a|1,z=0;
		if(f[k]){
			s[a]=t[k]?(m-l+1):0,t[a]=t[k],f[a]=1;
			s[b]=t[k]?(r-m):0,t[b]=t[k],f[b]=1;
			f[k]=0;
		}
		if(u<=m)z=qry(a,l,m);
		if(m<v)z+=qry(b,m+1,r);
		return z;
	}
}a[26];
int b[26];
char s[N];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,i,j,k,l,r;
	scanf("%d%d%s",&n,&m,s+1);
	for(i=1;i<=n;++i)j=s[i]-'a',a[j].u=a[j].v=i,a[j].w=1,a[j].upd(1,1,n);
	while(m--){
		scanf("%d%d",&l,&r),k=0;
		for(i=0;i<26;++i){
			a[i].u=l,a[i].v=r,b[i]=a[i].qry(1,1,n);
			if(b[i]&1)++k;
		}
		if(k>1)continue;
		for(i=0;i<26;++i)a[i].u=l,a[i].v=r,a[i].w=0,a[i].upd(1,1,n);
		for(i=0;i<26;++i)if(b[i]>1){
			a[i].u=l,l+=b[i]>>1,a[i].v=l-1,a[i].w=1,a[i].upd(1,1,n);
			a[i].v=r,r-=b[i]>>1,a[i].u=r+1,a[i].w=1,a[i].upd(1,1,n);
		}
		for(i=0;i<26;++i)if(b[i]&1)a[i].u=l,a[i].v=r,a[i].w=1,a[i].upd(1,1,n);
	}
	for(i=1;i<=n;++i)for(j=0;;++j){
		a[j].u=a[j].v=i;
		if(a[j].qry(1,1,n)){
			putchar(j+'a');
			break;
		}
	}
	return 0;
}