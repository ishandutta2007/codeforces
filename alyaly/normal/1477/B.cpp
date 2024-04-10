#include<bits/stdc++.h>
#define int long long
#define N 1000000
#define mid (l+r)/2
using namespace std;
int T,n,K,a[N+1],b[N+1],seg[N+1],laz[N+1];
string st,fi;
void segdown(int u,int l,int r){
	if(!laz[u])return;
	seg[u]=(laz[u]-1)*(r-l+1);
	if(l!=r){
		laz[u*2]=laz[u],laz[u*2+1]=laz[u];
	}
	laz[u]=0;
}
void segup(int u,int l,int r){segdown(u,l,r);if(l!=r){segdown(u*2,l,mid),segdown(u*2+1,mid+1,r),seg[u]=seg[u*2]+seg[u*2+1];}}
void segadd(int u,int l,int r,int nl,int nr,int np){
	if(l>nr||r<nl)return;
	else if(l>=nl&&r<=nr){
		laz[u]=np+1;
	}else{
		segdown(u,l,r);
		segadd(u*2,l,mid,nl,nr,np),segadd(u*2+1,mid+1,r,nl,nr,np);
		segup(u,l,r);
	}
}
int segreq(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl)return 0;
	else if(l>=nl&&r<=nr)return segdown(u,l,r),seg[u];
	else return segup(u,l,r),segreq(u*2,l,mid,nl,nr)+segreq(u*2+1,mid+1,r,nl,nr);
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		cin>>st>>fi;
		for(int i=1;i<=K;i++){
			cin>>a[i]>>b[i];
		}
		bool ffl=0;
		for(int i=1;i<=n;i++)segadd(1,1,n,i,i,fi[i-1]-'0');
		for(int i=K;i>=1;i--){
			int nt=segreq(1,1,n,a[i],b[i]),len=b[i]-a[i]+1;
			if(len%2==0&&nt==len/2){
				ffl=1;break;
			}else if(nt<=len/2)segadd(1,1,n,a[i],b[i],0);
			else segadd(1,1,n,a[i],b[i],1);
		}
		for(int i=1;i<=n;i++)if(segreq(1,1,n,i,i)!=st[i-1]-'0')ffl=1;
		if(!ffl)printf("YES\n");
		else printf("NO\n");
		for(int i=1;i<=4*n;i++)seg[i]=laz[i]=0;
	}
	return 0;
}