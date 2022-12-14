#include<bits/stdc++.h>
using namespace std;
map<int,int> M;
vector<pair<int,int> > V;
int a[404040];
int main()
{
	int n,I;
	scanf("%d%d",&n,&I);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		M[a[i]]++;
	}
	int k=I*8/n;
	k=min(k,30); 
	int K=min(n,(1<<k));
	for(auto x:M)
		V.push_back(x);
	int ans=n;
	for(int i=0;i<int(V.size());i++)
	{
		if(i>0)
			V[i].second+=V[i-1].second;
		if(i>=K)
			ans=min(ans,n-V[i].second+V[i-K].second);
		else
			ans=min(ans,n-V[i].second);
	}
	printf("%d\n",ans);
	return 0;
}