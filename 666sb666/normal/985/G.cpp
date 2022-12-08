#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int N=2e5+5;
int n,m,x[N],y[N],l[N],r[N];
LL A,B,C,ans;
vector<int> L[N],R[N];
set<pair<int,int> > st;
inline LL sum(int l,int r){return (LL)(l+r)*(r-l+1)/2;}
int main()
{
	scanf("%d%d%llu%llu%llu",&n,&m,&A,&B,&C);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
		st.insert(make_pair(x[i],y[i]));
		R[x[i]].push_back(y[i]);
		L[y[i]].push_back(x[i]);
	}
	for(int i=0;i<n;i++)sort(L[i].begin(),L[i].end()),sort(R[i].begin(),R[i].end());
	for(int i=0;i<n;i++)ans+=(LL)(n-i-1)*(n-i-2)/2*A*i;
	for(int i=0;i<n;i++)ans+=(LL)i*(n-i-1)*B*i;
	for(int i=0;i<n;i++)ans+=(LL)i*(i-1)/2*C*i;
	for(int i=0;i<n;i++)
		for(int j=0;j<R[i].size();j++)
		{
			int k=n-R[i][j]-1;if(k<0)continue;
			ans-=A*i*k+B*R[i][j]*k+C*sum(R[i][j]+1,n-1);
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<R[i].size();j++)
		{
			int k=i;if(k<0)continue;
			ans-=B*i*k+C*R[i][j]*k+A*sum(0,i-1);
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<R[i].size();j++)
		{
			int k=R[i][j]-i-1;if(k<0)continue;
			ans-=A*i*k+C*R[i][j]*k+B*sum(i+1,R[i][j]-1);
		}
	for(int i=0;i<n;i++)
	{
		ans+=(LL)R[i].size()*(R[i].size()-1)/2*A*i;
		for(int j=0;j<R[i].size();j++)ans+=B*R[i][j]*(R[i].size()-j-1)+C*R[i][j]*j;
	}
	for(int i=0;i<n;i++)
	{
		ans+=(LL)L[i].size()*R[i].size()*B*i;
		for(int j=0;j<L[i].size();j++)ans+=A*L[i][j]*R[i].size();
		for(int j=0;j<R[i].size();j++)ans+=C*R[i][j]*L[i].size();
	}
	for(int i=0;i<n;i++)
	{
		ans+=(LL)L[i].size()*(L[i].size()-1)/2*C*i;
		for(int j=0;j<L[i].size();j++)ans+=B*L[i][j]*j+A*L[i][j]*(L[i].size()-j-1);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<L[i].size();j++)l[L[i][j]]=1;
		for(int j=0;j<R[i].size();j++)r[R[i][j]]=1;
		if((LL)L[i].size()*R[i].size()*20<=m)
		{
			for(int j=0;j<L[i].size();j++)
				for(int k=0;k<R[i].size();k++)if(st.count(make_pair(L[i][j],R[i][k])))ans-=A*L[i][j]+B*i+C*R[i][k];
		}
		else for(int j=0;j<m;j++)if(l[x[j]]&&r[y[j]])ans-=A*x[j]+B*i+C*y[j];
		for(int j=0;j<L[i].size();j++)l[L[i][j]]=0;
		for(int j=0;j<R[i].size();j++)r[R[i][j]]=0;
	}
	printf("%llu\n",ans);
	return 0;
}