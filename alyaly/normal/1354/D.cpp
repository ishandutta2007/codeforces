#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#define mid (l+r)/2
using namespace std;
int n,Q,seg[4000001],ffl,p;
int qread(){
	int nans=0,nf=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') {
		c=getchar();
	}
	if(c=='-'){
		nf=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		nans*=10;
		nans+=c-'0';
		c=getchar();
	}
	return nf*nans;
}
void segadd(int u,int l,int r,int np){
	if(l>np||r<np) return;
	else{
		seg[u]++;
		if(l==r) return;
		if(np<=mid) segadd(u*2,l,mid,np);
		else segadd(u*2+1,mid+1,r,np);
		return;
	}
}
void segdec(int u,int l,int r,int np){
	if(l==r){
		seg[u]--;
		return;
	}
	seg[u]--;
	if(seg[u*2]>=np) segdec(u*2,l,mid,np);
	else segdec(u*2+1,mid+1,r,np-seg[u*2]);
	return;
}
void prans(int u,int l,int r){
	if(!seg[u]) return;
	if(l==r){
		printf("%d\n",l);
		ffl=1;
		return;
	}
	prans(u*2,l,mid);
	if(ffl) return;
	prans(u*2+1,mid+1,r);
	return;
}
signed main(){
//	freopen("P3369_3.in","r",stdin);
	n=qread();
	Q=qread();
	for(int i=1;i<=n;i++){
		p=qread();
		segadd(1,1,n,p);
	}
	for(int i=1;i<=Q;i++){
		p=qread();
		if(p>0) segadd(1,1,n,p);
		else segdec(1,1,n,-p);
//		for(int i=1;i<=4*n;i++) printf("%d ",seg[i]);printf("\n");
	}
	if(!seg[1]) printf("0\n");
	else{
		prans(1,1,n);
	}
	return 0;
}