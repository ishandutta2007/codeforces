#include<bits/stdc++.h>
using namespace std;
int zb[45],zz[25];
int gw[1<<20];
int main(){
	int n,k;
	cin>>n>>k;
	int L=max(n/2,1),R=n-L;
	for(int i=0;i<L;++i)zb[i]=1<<i;
	for(int i=L;i<n;++i)zb[i]=1<<(i-L);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j){
		int aa;
		scanf("%d",&aa);
		if(j<=i||!aa)continue;
		if(j<L)zb[i]|=1<<j,zb[j]|=1<<i;
		else if(i>=L)zb[i]|=1<<(j-L),zb[j]|=1<<(i-L);
		else zz[i]|=1<<(j-L);
	}
	for(int i=0;i<(1<<R);++i){
		int yy=(1<<R)-1,pc=0;
		for(int j=0;j<R;++j)if(i&(1<<j)){
			yy&=zb[j+L],++pc;
		}
		if((yy&i)==i)gw[i]=pc;
	}
	for(int i=0;i<R;++i)for(int j=0;j<(1<<R);j+=1<<(i+1))
		for(int l=j;l<j+(1<<i);++l)
			gw[l^(1<<i)]=max(gw[l^(1<<i)],gw[l]);
	int mx=0;
	for(int i=0;i<(1<<L);++i){
		int xx=(1<<L)-1,pc=0,yy=(1<<R)-1;
		for(int j=0;j<L;++j)if(i&(1<<j)){
			xx&=zb[j],yy&=zz[j],++pc;
		}
		if((xx&i)==i)mx=max(mx,pc+gw[yy]);
	}
	printf("%.10f\n",1.0*k*k/2/mx*(mx-1));
	return 0;
}