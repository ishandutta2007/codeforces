#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005,M=5001,P=1e9+7;
int n,cc,p1,p2,hs,s[M],vis[M],pr[M],id[M],lst[M],sp[M][M],hsh[M][M];
map<int,int>mp;
inline bool chk(int l)
{
	mp.clear();
	for(int i=1;i<M;i++)
	{
		int h=hsh[i][l];mp[h]+=s[i];
		if(mp[h]>n/2){p1=i;hs=h;return 1;}
	} 
	return 0;
}
inline bool chk2(int l1,int l2)
{
	int ss=0;
	for(int i=1;i<M;i++)if(hsh[i][l1]==hs&&sp[i][l1+1]>=l2)
	{
		int h=hsh[i][l1];ss+=s[i];
		if(ss>n/2){p2=i;return 1;}
	} 
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),s[max(x,1)]++;
	for(int i=2;i<M;i++)
	{
		if(!vis[i])pr[++cc]=i,id[i]=cc,lst[i]=cc;
		for(int j=1;j<=cc&&i*pr[j]<M;j++)
		{
			vis[i*pr[j]]=1;lst[i*pr[j]]=j;
			if(i%pr[j]==0)break;
		}
	}
	for(int i=2;i<M;i++)
	{
		for(int j=1;j<=cc;j++)sp[i][j]=sp[i-1][j];
		for(int t=i;t>1;t/=pr[lst[t]])sp[i][cc+1-lst[t]]++;
	}
	for(int i=1;i<M;i++)for(int j=1;j<=cc;j++)hsh[i][j]=(233ll*hsh[i][j-1]+sp[i][j])%P;
	int l1=0;
	{
		int l=0,r=cc;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(chk(mid))l=mid;else r=mid-1;
		}
		chk(l);l1=l;
	}
	p2=p1;int l2=0;
	if(l1<cc)
	{
		int l=0,r=M*12;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(chk2(l1,mid))l=mid;else r=mid-1;
		}
		l2=l;
	}
	ll ans=0;
	for(int i=1;i<M;i++)if(s[i])
	{
		int res=0;
		if(hsh[i][l1]==hs)
		{
			res+=abs(sp[i][l1+1]-l2);
			for(int k=l1+2;k<=cc;k++)res+=sp[i][k];
		}
		else
		{
			for(int j=1;j<=l1;j++)if(hsh[i][j]!=hsh[p2][j])
			{
				res+=abs(sp[i][j]-sp[p2][j]);
				for(int k=j+1;k<=l1;k++)res+=sp[p2][k];
				res+=l2;
				for(int k=j+1;k<=cc;k++)res+=sp[i][k];
				break;
			}
		}
		ans+=1ll*res*s[i];
	}
	printf("%lld\n",ans);
	return 0;
}