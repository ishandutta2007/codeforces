#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 524288
long long idx1[2*MAXN];
long long maxi1[2*MAXN];
long long idx2[2*MAXN];
long long maxi2[2*MAXN];
pair<long long,int> getmax1(int l,int r)
{
	l+=MAXN;
	r+=MAXN;
	int maxin=-1;
	long long int ans=-998877665544332211LL;
	while(l<=r)
	{
		if(l%2==1)
		{
			if(ans<idx1[l])
			{
				ans=idx1[l];
				maxin=maxi1[l];
			}
			l++;
		}
		if(r%2==0)
		{
			if(ans<idx1[r])
			{
				ans=idx1[r];
				maxin=maxi1[r];
			}
			r--;
		}
		l/=2;
		r/=2;
	}
	return make_pair(ans,maxin);
}
pair<long long,int> getmax2(int l,int r)
{
	l+=MAXN;
	r+=MAXN;
	int maxin=-1;
	long long int ans=-998877665544332211LL;
	while(l<=r)
	{
		if(l%2==1)
		{
			if(ans<idx2[l])
			{
				ans=idx2[l];
				maxin=maxi2[l];
			}
			l++;
		}
		if(r%2==0)
		{
			if(ans<idx2[r])
			{
				ans=idx2[r];
				maxin=maxi2[r];
			}
			r--;
		}
		l/=2;
		r/=2;
	}
	return make_pair(ans,maxin);
}
int N,M;
long long d[MAXN];
long long h[MAXN];
long long dsum[MAXN];
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%I64d",d+i);
	for(int i=0;i<N;i++)
		scanf("%I64d",h+i);
	dsum[0]=0;
	for(int i=1;i<=N;i++)
		dsum[i]=dsum[i-1]+d[i-1];
	for(int i=N+1;i<2*N;i++)
		dsum[i]=dsum[i-1]+d[i-N-1];
	for(int i=0;i<2*N;i++)
	{
		idx1[MAXN+i]=2*h[i%N]+dsum[i];
		maxi1[MAXN+i]=i;
		idx2[MAXN+i]=2*h[i%N]-dsum[i];
		maxi2[MAXN+i]=i;
	}
	for(int i=MAXN-1;i>=1;i--)
	{
		idx1[i]=max(idx1[2*i],idx1[2*i+1]);
		idx2[i]=max(idx2[2*i],idx2[2*i+1]);
		if(idx1[2*i]>idx1[2*i+1])
			maxi1[i]=maxi1[2*i];
		else
			maxi1[i]=maxi1[2*i+1];
		if(idx2[2*i]>idx2[2*i+1])
			maxi2[i]=maxi2[2*i];
		else
			maxi2[i]=maxi2[2*i+1];
	}
	for(int i=0;i<M;i++)
	{
		int tl,tr;
		scanf("%d%d",&tl,&tr);
		tl--;tr--;
		int l,r;
		if(tl<=tr)
		{
			l=tr+1;
			r=N+tl-1;
		}
		else
		{
			l=tr+1;
			r=tl-1;
		}
		//printf("%d %d\n",l,r);
		pair<long long,int> maxres1=getmax1(l,r);
		pair<long long,int> maxres2=getmax2(l,r);
		/*
		printf("%I64d %d\n",maxres1.first,maxres1.second);
		printf("%I64d %d\n",getmax2(l,maxres1.second-1).first,getmax2(l,maxres1.second-1).second);
		printf("%I64d %d\n",getmax2(maxres1.second+1,r).first,getmax2(maxres1.second+1,r).second);
		printf("%I64d %d\n",maxres2.first,maxres2.second);
		printf("%I64d %d\n",getmax1(l,maxres2.second-1).first,getmax1(l,maxres2.second-1).second);
		printf("%I64d %d\n",getmax1(maxres2.second+1,r).first,getmax1(maxres2.second+1,r).second);
		*/
		printf("%I64d\n",
			max(
				maxres1.first+max(getmax2(l,maxres1.second-1).first,getmax2(maxres1.second+1,r).first ),
				maxres2.first+max(getmax1(l,maxres2.second-1).first,getmax1(maxres2.second+1,r).first )
			)
		);
	}
	return 0;
}