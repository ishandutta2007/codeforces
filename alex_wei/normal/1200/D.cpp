#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
const int inf=1e9;
int n,k,l[2002],r[2002],u[2002],d[2002],able[2002][2002],p[2002],ans,b[2002][2002],ori;
char c[2002][2002];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++){
		int pd=1;
		for(int j=1;j<=n;j++)
			if(c[i][j]=='B')pd=0;
		ori+=pd;
	}
	for(int i=1;i<=n;i++){
		int pd=1;
		for(int j=1;j<=n;j++)
			if(c[j][i]=='B')pd=0;
		ori+=pd;
	}
	for(int i=1;i<=n;i++){
		l[i]=inf,r[i]=-inf;
		for(int j=1;j<=n;j++){
			if(c[i][j]=='B')
				l[i]=min(l[i],j),r[i]=max(r[i],j);
		}
		u[i]=inf,d[i]=-inf;
		for(int j=1;j<=n;j++)
			if(c[j][i]=='B')
				u[i]=min(u[i],j),d[i]=max(d[i],j);
	}
	for(int i=1;i<=n;i++){
		if(r[i]>0)
			for(int j=r[i]-k+1;j<=l[i];j++)
				able[i][j]=1;
	}
	for(int i=n;i>0;i--)
		for(int j=n;j>0;j--)
			able[i][j]+=able[i+1][j];
	for(int i=1;i<=n-k+1;i++){
		memset(p,0,sizeof(p));
		for(int j=1;j<=n;j++){
			if(u[j]==inf)p[j]=0;
			else p[j]=(u[j]>=i&&d[j]<=i+k-1);
		}
		int su=0;
		for(int j=1;j<k;j++)su+=min(1,p[j]);
		for(int j=k;j<=n;j++){
			su+=min(p[j],1);
			if(p[j-k]==1)su--;
			ans=max(ans,ori+su+able[i][j-k+1]-able[i+k][j-k+1]);
		}
	} 
	cout<<max(ori,ans);
	return 0;
}
/*
2 1
BW
WW
*/