//Code by John Alfnov
//Please orz Qingyu
//Hydd txdy
#include<bits/stdc++.h>
using namespace std;
int nf,ne,ns;
int rf,re,rs;
double xf,xe,xs;
int df,de;
int bf[25],BL=13,LB=20;
double ans=0;
pair<double,int>uq[55];
double zb[55],dp[25][25],qh[55];
int gs[55];
void dfs(int stp,int sx){
	if((BL-stp+1)*2<sx)return;
	if(stp>BL){
		int tt=0;
		for(int i=1;i<=BL;++i){
			uq[++tt]=make_pair(i-xs,bf[i]);
			uq[++tt]=make_pair(i+xs,-bf[i]);
		}
		sort(uq+1,uq+tt+1);
		uq[tt+1].first=2e9;
		for(int i=1;i<=tt;++i){
			zb[i]=uq[i].first;
			gs[i]=gs[i-1]+uq[i].second;
			if(fabs(zb[i]-uq[i+1].first)<1e-10){
				int j=i;
				while(j>1&&fabs(zb[j-1]-zb[j])<1e-10)--j;
				for(int k=j;k<i;++k)gs[k]=gs[i];
			}
		}
		for(int i=1;i<=tt;++i){
			qh[i]=qh[i-1]+(zb[i]-zb[i-1])*(1+gs[i-1]);
		}
		zb[0]=-2e9,zb[tt+1]=2e9;
		int sum=0;
		for(int i=0;i<=nf;++i)for(int j=0;j<=ne;++j)
			dp[i][j]=0;
		for(int i=1;i<=BL;++i){
			double lf=0,le=0;
			sum+=2-bf[i];
			if(bf[i]!=2){
				double L,R,dj;
				int w1,w2;
				L=i-xf,R=i+xf,dj=0;
				w1=lower_bound(zb+1,zb+tt+1,L)-zb;
				w2=upper_bound(zb+1,zb+tt+1,R)-zb-1;
				if(w1>w2)dj=(1+gs[w2])*(R-L);
				else{
					dj=(1+gs[w1-1])*(zb[w1]-L)+(1+gs[w2])*(R-zb[w2]);
					dj+=qh[w2]-qh[w1];
				}
				lf=dj*df;
				L=i-xe,R=i+xe,dj=0;
				w1=lower_bound(zb+1,zb+tt+1,L)-zb;
				w2=upper_bound(zb+1,zb+tt+1,R)-zb-1;
				if(w1>w2)dj=(1+gs[w2])*(R-L);
				else{
					dj=(1+gs[w1-1])*(zb[w1]-L)+(1+gs[w2])*(R-zb[w2]);
					dj+=qh[w2]-qh[w1];
				}
				le=dj*de;
			}
			for(int j=nf;j>=0;--j)for(int k=ne;k>=0;--k)
				for(int l1=0;l1<=2-bf[i]&&l1<=j;++l1)
					for(int l2=0;l2<=2-bf[i]-l1&&l2<=k;++l2){
						double dj=dp[j-l1][k-l2];
						dj+=l1*lf+l2*le;
						dp[j][k]=max(dp[j][k],dj);
					}
		}
		ans=max(ans,dp[nf][ne]);
		return;
	}
	for(int i=0;i<=2&&i<=sx;++i){
		bf[stp]=i;
		dfs(stp+1,sx-i);
	}
}
int main(){
	cin>>nf>>ne>>ns;
	cin>>rf>>re>>rs;
	cin>>df>>de;
	xf=sqrt(1.0*rf*rf-1);
	xe=sqrt(1.0*re*re-1);
	xs=sqrt(1.0*rs*rs-1);
	dfs(1,ns);
	printf("%.14f\n",ans);
	return 0;
}