#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 131072
int N,S,L;
int AMAX[2*MAXN];
int AMIN[2*MAXN];
int getmax(int l,int r)
{
	l+=MAXN;
	r+=MAXN;
	int ans=AMAX[l];
	while(l<=r)
	{
		if(l%2==1)
		{
			ans=max(ans,AMAX[l]);
			l++;
		}
		if(r%2==0)
		{
			ans=max(ans,AMAX[r]);
			r--;
		}
		l/=2;
		r/=2;
	}
	return ans;
}
int getmin(int l,int r)
{
	l+=MAXN;
	r+=MAXN;
	int ans=AMIN[l];
	while(l<=r)
	{
		if(l%2==1)
		{
			ans=min(ans,AMIN[l]);
			l++;
		}
		if(r%2==0)
		{
			ans=min(ans,AMIN[r]);
			r--;
		}
		l/=2;
		r/=2;
	}
	return ans;
}
int DP[2*MAXN];
void dpupdate(int a,int v)
{
	a+=MAXN;
	DP[a]=v;
	while(a!=1)
	{
		a/=2;
		DP[a]=min(DP[2*a],DP[2*a+1]);
	}
}
int getdpmin(int l,int r)
{
	l+=MAXN;
	r+=MAXN;
	int ans=987654321;
	while(l<=r)
	{
		if(l%2==1)
		{
			ans=min(ans,DP[l]);
			l++;
		}
		if(r%2==0)
		{
			ans=min(ans,DP[r]);
			r--;
		}
		l/=2;
		r/=2;
	}
	return ans;
} 
int main()
{
	scanf("%d%d%d",&N,&S,&L);
	for(int i=0;i<N;i++)
	{
		int t;
		scanf("%d",&t);
		AMAX[MAXN+i]=t;
		AMIN[MAXN+i]=t;
	}
	for(int i=MAXN-1;i>=1;i--)
	{
		AMAX[i]=max(AMAX[2*i],AMAX[2*i+1]);
		AMIN[i]=min(AMIN[2*i],AMIN[2*i+1]);
	}
	dpupdate(0,0);
	for(int i=0;i<N;i++)
	{
		int lo=-1;
		int hi=i;
		while(lo+1!=hi)
		{
			int mi=(1+lo+hi)/2;
			if(getmax(mi,i)-getmin(mi,i)>S) lo=mi;
			else hi=mi;
		}
		lo++;
	//	printf("%d %d\n",getmax(lo,i),getmin(lo,i));
		dpupdate(i+1,1+getdpmin(lo,i-L+1));
//		printf("<%d, %d>\n",lo,DP[MAXN+i+1]);
		//[lo,i-l+1] 
	}
	if(DP[MAXN+N]>1000000) puts("-1");
	else printf("%d\n",DP[MAXN+N]);
	return 0;
}

// 1 3 1 2 4 [1 2