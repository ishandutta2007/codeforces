#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N][2];
long long round_ud(long long p,long long q,int dir){
	long long r=p/q,t=p%q;
	if(t==0) return r;
	if(dir){
		if(t<0) return r;
		else return r+1;
	}
	else{
		if(t<0) return r-1;
		else return r;
	}
	
}
int main(){
	int l[2]={-1,-1},r[2]={-1,-1};
	int n,m=0;
	double sum[2]={},p1[2]={},p2[2]={},p0[2]={},cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&a[i][j]);
			if(l[j]<0 || a[i][j]<a[l[j]][j]) l[j]=i;
			if(r[j]<0 || a[i][j]>a[r[j]][j]) r[j]=i;
		}
	}
	for(int j=0;j<2;j++){
		int s[2]={l[j],l[j]},mv[2]={1,n-1};
		for(int k=0;k<2;k++){
			while(a[(s[k]+mv[k])%n][j]==a[s[k]][j]) s[k]=(s[k]+mv[k])%n;
		}
		double sc=abs(a[s[1]][j^1]-a[s[0]][j^1])+1;
		cnt+=sc*(sc-1)/2;
		p0[j]=sc;
		p1[j]=sc*a[l[j]][j];
		p2[j]=sc*a[l[j]][j]*a[l[j]][j];
		for(int x=a[l[j]][j]+1;x<=a[r[j]][j];x++){
			long long p[2],q[2];
			for(int k=0;k<2;k++){
				while(a[s[k]][j]<x && a[(s[k]+mv[k])%n][j]<=x) s[k]=(s[k]+mv[k])%n;
				int px=a[s[k]][j],py=a[s[k]][j^1];
				int nx=a[(s[k]+mv[k])%n][j],ny=a[(s[k]+mv[k])%n][j^1];
				if(x==px)  p[k]=py,q[k]=1;
				else{
					p[k]=1LL*py*(nx-px)+1LL*(x-px)*(ny-py);
					q[k]=nx-px;
				}
			}
			int large=0;
			if(p[0]*q[1]<p[1]*q[0]) large=1;
			double ty[2];
			for(int k=0;k<2;k++){
				ty[k]=round_ud(p[k],q[k],k^large);
			}
			sc=ty[large]-ty[large^1]+1;
			sum[j]+=sc*(p2[j]-2*p1[j]*x+p0[j]*x*x);
			cnt+=sc*p0[j]+sc*(sc-1)/2;
			p0[j]+=sc;
			p1[j]+=sc*x;
			p2[j]+=sc*x*x;
		}
	}
	printf("%.8f\n",1.0*(sum[0]+sum[1])/cnt);
}