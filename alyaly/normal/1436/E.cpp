#include<bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define inf 999999999
using namespace std;
int n,m,a[200001],pre[200001],ls[200001];
int seg[800001];
void segadd(int u,int l,int r,int np,int nx){
	if(l==r)seg[u]=nx;
	else{
		if(np<=mid)segadd(u*2,l,mid,np,nx);
		else segadd(u*2+1,mid+1,r,np,nx);
		seg[u]=min(seg[u*2],seg[u*2+1]);
	}
}
int segreq(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl)return inf;
	else if(l>=nl&&r<=nr)return seg[u];
	else return min(segreq(u*2,l,mid,nl,nr),segreq(u*2+1,mid+1,r,nl,nr));
}
bool chk(int l,int r){
	if(l>r)return 0;
	return segreq(1,1,m,r+1,m)>=l;
}
signed main(){
	cin>>n;m=2*n;for(int i=1;i<=4*m;i++)seg[i]=inf;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=ls[a[i]];
		ls[a[i]]=i;
	}
	for(int i=n+1;i<=2*n;i++){
		a[i]=i-n,pre[i]=ls[i-n];
	}
	for(int ii=n+1;ii<=2*n;ii++){
		bool nfl=0;
		for(int i=ii;i;i=pre[i]){
			if(chk(pre[i]+1,min(n,i-1))){
				nfl=1;break;
			}
		}
		if(!nfl){
			printf("%lld\n",ii-n);return 0;
		}
		for(int i=ii;i;i=pre[i]){
			segadd(1,1,m,i,pre[i]);
		}
	}
	if(segreq(1,1,m,n+1,m)<1)printf("%lld\n",n+1);
	else printf("%lld\n",n+2);
	return 0;
}
/*
4
1 3 2 3

5
1 2 3 4 5
*/