#include <bits/stdc++.h>
using namespace std;
int arr[200005],f[200005],l[200005],cnt[200005];
int get(int l,int r)
{
	int f=0;
	for (int i=l;i<=r;i++)
	{
		cnt[arr[i]]++;
		f=max(f,cnt[arr[i]]);
	}
	for (int i=l;i<=r;i++)
	cnt[arr[i]]--;
	return r-l+1-f;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if (!f[arr[i]])
		f[arr[i]]=i;
		l[arr[i]]=i;
	}
	set<pair<int,int> > s;
	for (int i=1;i<=n;i++)
	s.insert({f[arr[i]],l[arr[i]]});
	int curl=0,curr=0,ans=0;
	for (auto p:s)
	{
		if (p.first>curr)
		{
			ans+=get(curl,curr);
			curl=p.first;
			curr=p.second;
		}
		else
		curr=max(curr,p.second);
	}
	printf("%d",ans+get(curl,curr));
}