#include<bits/stdc++.h>
#define AA 6
using namespace std;
int A=AA;
struct apple{
	int a[6],w;
	bool operator<(const apple &other)const{
		return w<other.w;
	}
}e[100005],z1[100000/AA+5],z2[100000/AA+5];
bitset<100000/AA+5>bs[100000/AA*5*2+5];
int bb[100000/AA*5*2+5];
int cd[AA+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=2e9+10000;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)scanf("%d",&e[i].a[j]);
		scanf("%d",&e[i].w);
	}
	sort(e+1,e+n+1);
	A=min(A,n);
	int bz=(n-1)/A+1;
	for(int i=1;i<=A;++i)cd[i]=bz;
	int he=A*bz;
	for(int i=1;i<=A;++i)if(he>n){
		--cd[i],--he;
	}
	for(int i=1;i<=A;++i)cd[i]+=cd[i-1];
	for(int L=1;L<=A;++L)for(int R=L;R<=A;++R){
		int tt=0;
		for(int i=cd[R-1]+1;i<=cd[R];++i)
			for(int j=1;j<=m;++j)bb[++tt]=e[i].a[j];
		for(int i=cd[L-1]+1;i<=cd[L];++i)
			for(int j=1;j<=m;++j)bb[++tt]=e[i].a[j];
		sort(bb+1,bb+tt+1);
		for(int i=1;i<=tt;++i)bs[i].reset();
		for(int i=1;i<=cd[R]-cd[R-1];++i){
			int ww=i+cd[R-1];
			z2[i].w=e[ww].w;
			for(int j=1;j<=m;++j){
				int wz=lower_bound(bb+1,bb+tt+1,e[ww].a[j])-bb;
				z2[i].a[j]=wz;
				bs[wz][i-1]=1;
			}
		}
		for(int i=1;i<=cd[L]-cd[L-1];++i){
			int ww=i+cd[L-1];
			z1[i].w=e[ww].w;
			bitset<100000/AA+5>ss;
			for(int j=1;j<=m;++j){
				int wz=lower_bound(bb+1,bb+tt+1,e[ww].a[j])-bb;
				z1[i].a[j]=wz;
				ss|=bs[wz];
			}
			ss=~ss;
			int zz=ss._Find_first();
			if(zz>=cd[R]-cd[R-1])continue;
			ans=min(ans,z2[zz+1].w+z1[i].w);
		}
	}
	if(ans>2e9+5)ans=-1;
	printf("%d\n",ans);
	return 0;
}