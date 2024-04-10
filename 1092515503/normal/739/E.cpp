#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int n,a,b,F[2010][2010],G[2010][2010];
double p[2010],q[2010],f[2010][2010];
int cmp(double ip){
	if(ip>eps)return 1;
	if(ip<-eps)return -1;
	return 0;
}
void trans(int i,int j,int I,int J,double k,int K){
	if(cmp(f[I][J]-k)==-1)f[I][J]=k,F[I][J]=F[i][j]+K,G[I][J]=G[i][j]+K;
	else if(cmp(f[I][J]-k)==0)F[I][J]=min(F[I][J],F[i][j]+K),G[I][J]=max(G[I][J],G[i][j]+K);
}
int che(double ip){
	for(int i=1;i<=n;i++)for(int j=0;j<=min(i,a);j++)f[i][j]=-n;
	for(int i=0;i<n;i++)for(int j=0;j<=min(i,a);j++){
		if(j+1<=a){
			trans(i,j,i+1,j+1,f[i][j]+p[i+1],0);
			trans(i,j,i+1,j+1,f[i][j]+1-(1-p[i+1])*(1-q[i+1])-ip,1);
		}
		trans(i,j,i+1,j,f[i][j],0);
		trans(i,j,i+1,j,f[i][j]+q[i+1]-ip,1);
	}
	if(F[n][a]>b)return 1;
	if(G[n][a]<b)return -1;
	printf("%lf\n",f[n][a]+ip*b);
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++)scanf("%lf",&q[i]);
	double l=0,r=1,mid;
	while(true){
		int tp=che(mid=(l+r)/2);
		if(tp==1)l=mid;
		if(tp==-1)r=mid;
		if(!tp)break;
	}
	return 0;
}