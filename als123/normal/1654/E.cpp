#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const int N=100005;
int n;
int a[N];
map<int,int> mp;
int tot[200000];
vector<int> vec;
int solve ()
{
	int cnt=0;
	for (int d=0;d<=100;d++)
	{
		mp.clear();
		for (int i=1;i<=n;i++)
		{
			mp[a[i]-i*d]++;
		}
		for (auto it:mp)
			cnt=max(cnt,it.second);
	}
	
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=min(n,i+1000);j++)
		{
			int x=(a[j]-a[i]);
			if (x%(j-i)==0)
			{
				int p=x/(j-i)+100000;
				vec.push_back(p);
				tot[p]++;
				cnt=max(cnt,tot[p]+1);
			}
		}
		while (!vec.empty()) 
		{
			tot[vec.back()]=0;
			vec.pop_back();
		}
	}
	return n-cnt;
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	int ans=solve();
	for (int u=1;u<=n;u++) a[u]=-a[u];
	ans=min(ans,solve());
	printf("%d\n",ans);
	return 0;
}