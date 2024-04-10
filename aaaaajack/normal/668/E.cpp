#include<bits/stdc++.h>
#define N 2010
using namespace std;
bitset<N> a[N],b[N];
bool ska[N],skb[N];
int xa[N],xb[N];
inline void fix(int &a){
	if(a>0) a=(a-1)<<1;
	else a=(-a-1)<<1|1;
}
void fill(int u,int n,bitset<N> arr[],int val[]){
	val[u]=1;
	val[u^1]=-1;
	for(int i=0;i<n*2;i++){
		if(arr[u][i]&&!val[i]) fill(i,n,arr,val);
	}
}
int main(){
	int n,m1,m2,x1,x2;
	bool gga=false,ggb=false;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++){
		scanf("%d%d",&x1,&x2);
		fix(x1),fix(x2);
		a[x1^1][x2]=true;
		a[x2^1][x1]=true;
	}
	for(int i=0;i<m2;i++){
		scanf("%d%d",&x1,&x2);
		fix(x1),fix(x2);
		b[x1^1][x2]=true;
		b[x2^1][x1]=true;
	}
	for(int i=0;i<n*2;i++){
		for(int j=0;j<n*2;j++){
			if(a[j][i]) a[j]|=a[i];
			if(b[j][i]) b[j]|=b[i];
		}
	}
	for(int i=0;i<n;i++){
		if(a[i<<1][i<<1|1]&&a[i<<1|1][i<<1]) gga=true;
		if(b[i<<1][i<<1|1]&&b[i<<1|1][i<<1]) ggb=true;
	}
	if(gga&&ggb) puts("SIMILAR");
	else if(gga){
		for(int i=0;i<n*2;i++){
			if(b[i^1][i]) xb[i]=1,xb[i^1]=-1;
		}
		for(int i=0;i<n*2;i++){
			if(!xb[i]) fill(i,n,b,xb);
		}
		for(int i=0;i<n;i++){
			printf("%d ",xb[i<<1]==1);
		}
	}
	else if(ggb){
		for(int i=0;i<n*2;i++){
			if(a[i^1][i]) xa[i]=1,xa[i^1]=-1;
		}
		for(int i=0;i<n*2;i++){
			if(!xa[i]) fill(i,n,a,xa);
		}
		for(int i=0;i<n;i++){
			printf("%d ",xa[i<<1]==1);
		}
	}
	else{
		bool sim=true;
		int gi,gj;
		for(int i=0;i<n*2;i++){
			for(int j=0;j<n*2;j++){
				if(j==i) continue;
				if(a[i][j]!=b[i][j]){
					sim=false;
					gi=i;
					gj=j;
				}
			}
			if(a[i][i^1]) xa[i^1]=1,xa[i]=-1;
			if(b[i][i^1]) xb[i^1]=1,xb[i]=-1;
		}
		if(sim) puts("SIMILAR");
		else{
			if(a[gi][gj]){
				if(!xb[gj^1]) fill(gj^1,n,b,xb);
				if(!xb[gi]) fill(gi,n,b,xb);
				for(int i=0;i<n*2;i++){
					if(!xb[i]) fill(i,n,b,xb);
				}
				for(int i=0;i<n;i++){
					if(xb[i<<1]==1) printf("%d ",1);
					else printf("%d ",0);
				}
			}
			else{
				if(!xa[gj^1]) fill(gj^1,n,a,xa);
				if(!xa[gi]) fill(gi,n,a,xa);
				for(int i=0;i<n*2;i++){
					if(!xa[i]) fill(i,n,a,xa);
				}
				for(int i=0;i<n;i++){
					if(xa[i<<1]==1) printf("%d ",1);
					else printf("%d ",0);
				}
			}
		}
	}
	return 0;
}