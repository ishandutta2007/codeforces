#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005];
int zz1,zz2;
int hw[200005],lw[200005];
long long S[200005];
long long suan0(int x,int y){
	long long a1=0;
	long long a2=0;
	if(hw[x]<y)a1=1ll*lw[y]*y+S[x]-S[lw[y]];
	else a1=1ll*x*y;
	if(x<n){
		if(hw[x+1]<=y)a2=1ll*(n-x)*(m-y);
		else a2=1ll*(n-lw[y])*(m-y)+1ll*m*(lw[y]-x)-S[lw[y]]+S[x];
	}
	return a1+a2;
}
long long suan1(int x,int y){
	long long a1=0;
	long long a2=0;
	if(hw[x]<y)a1=1ll*lw[y]*y+S[x]-S[lw[y]];
	else a1=1ll*x*y;
	if(x<n){
		if(hw[x+1]<=y)a2=1ll*(n-x)*(m-y);
		else a2=1ll*(n-lw[y])*(m-y)+1ll*m*(lw[y]-x)-S[lw[y]]+S[x];
	}
	if(hw[zz1]>=zz2){
		if(zz1<=x&&zz2<=y)--a1;
	}else{
		if(x<zz1&&y<zz2)--a2;
	}
	return a1+a2;
}
long long dlj0(){
	long long ans=max(S[n],1ll*n*m-S[n]);
	int wz=1;
	for(int i=1;i<=n;++i){
		while(wz<m&&suan0(i,wz+1)>=suan0(i,wz)){
			++wz;
		}
		ans=max(ans,suan0(i,wz));
	}
	return ans;
}
long long dlj1(){
	long long ans;
	if(hw[zz1]>=zz2)ans=max(S[n]-1,1ll*n*m-S[n]);
	else ans=max(S[n],1ll*n*m-S[n]-1);
	int wz=1;
	for(int i=1;i<=n;++i){
		while(wz<m&&suan1(i,wz+1)>=suan1(i,wz)){
			++wz;
		}
		ans=max(ans,suan1(i,wz));
	}
	return ans;
}
bool check(int x){
	int w1=m;
	hw[0]=w1;
	for(int i=1;i<=n;++i){
		while(w1&&a[i]+b[w1]>x)--w1;
		hw[i]=w1;
	}
	int w2=n;
	lw[0]=w2;
	for(int i=1;i<=m;++i){
		while(w2&&b[i]+a[w2]>x)--w2;
		lw[i]=w2;
	}
	S[0]=0;
	for(int i=1;i<=n;++i){
		S[i]=S[i-1]+hw[i];
	}
	if(dlj0()==dlj1()+1)return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	int qa=a[1],qb=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	zz1=lower_bound(a+1,a+n+1,qa)-a;
	zz2=lower_bound(b+1,b+m+1,qb)-b;
	int L=a[1]+b[1],R=qa+qb;
	while(L<=R){
		int mid=(L+R)>>1;
		if(!check(mid))L=mid+1;
		else R=mid-1;
	}
	L=min(L,qa+qb);
	printf("%d\n",L);
	return 0;
}