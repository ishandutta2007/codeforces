#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int BBB=320;
const int N=100000;
int n,m,BLK[100100],lp[100100],lim,las[100100],ini[100100],hea[100100],bon[100100],sal[400];
ll res[315][100100],ans;
void breakblock(int x){
	if(sal[x]==-1)return;
	for(int i=lp[x];i<lp[x+1];i++)las[i]=sal[x];
	sal[x]=-1;
}
void modpoint(int x,int tim){ans+=min(1ll*bon[x],1ll*hea[x]*(tim-las[x])+(ini[x]*!las[x])),las[x]=tim;}
void modblock(int x,int tim){
	if(sal[x]==-1)for(int i=lp[x];i<lp[x+1];i++)modpoint(i,tim);else ans+=res[x][min(N,tim-sal[x])];
	sal[x]=tim;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)BLK[i]=i/BBB;
	BLK[n]=lim=BLK[n-1]+1,lp[lim]=n;
	for(int i=0;i<lim;i++)lp[i]=i*BBB,sal[i]=-1;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&ini[i],&bon[i],&hea[i]),hea[i]=min(hea[i],bon[i]);
		if(!hea[i])continue;
		res[BLK[i]][1]+=hea[i];
		res[BLK[i]][bon[i]/hea[i]+1]-=hea[i]-bon[i]%hea[i];
		res[BLK[i]][bon[i]/hea[i]+2]-=bon[i]%hea[i]; 
	}
	for(int i=0;i<lim;i++){
		for(int j=1;j<=N;j++)res[i][j]+=res[i][j-1];
		for(int j=1;j<=N;j++)res[i][j]+=res[i][j-1];
//		for(int j=1;j<=30;j++)printf("%d ",res[i][j]);puts("");
	}
	scanf("%d",&m);
	for(int i=1,l,r,t;i<=m;i++){
		ans=0;
		scanf("%d%d%d",&t,&l,&r),l--,r--;
		if(BLK[l]==BLK[r]){
			breakblock(BLK[l]);
			for(int j=l;j<=r;j++)modpoint(j,t);
		}else{
			breakblock(BLK[l]),breakblock(BLK[r]);
			for(int j=l;j<lp[BLK[l]+1];j++)modpoint(j,t);
			for(int j=lp[BLK[r]];j<=r;j++)modpoint(j,t);
			for(int j=BLK[l]+1;j<BLK[r];j++)modblock(j,t);
		}
		printf("%lld\n",ans);
	}
	return 0;
}