#include<bits/stdc++.h>
using namespace std;
double p[1005][1005];
double he[1005],e[1005];
double bz[1005];
int vist[1005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
		int zz;
		scanf("%d",&zz);
		p[i][j]=zz/100.0;
	}
	for(int i=1;i<n;++i)bz[i]=1,he[i]=0,e[i]=1e100;
	he[n]=e[n]=0;
	for(int k=1;k<n;++k){
		double mn=1e100;
		int wz=1;
		for(int i=1;i<=n;++i)if(!vist[i]){
			if(mn>e[i])mn=e[i],wz=i;
		}
		vist[wz]=1;
		for(int i=1;i<=n;++i)if(!vist[i]){
			he[i]+=bz[i]*p[i][wz]*(e[wz]+1);
			bz[i]*=(1-p[i][wz]);
			if(bz[i]<1)e[i]=(he[i]+bz[i])/(1-bz[i]);
			else e[i]=1e100;
		}
	}
	printf("%.10f\n",e[1]);
	return 0;
}