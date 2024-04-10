#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("sse4")
#pragma GCC optimize ("O3")
#define N (51*1000)
#define MOD ((int)1e9+7)

int n,m,a[N],now;

int main()
{
	scanf("%d%d",&n,&m);
	int m2=m;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int t=30;t>=0;t--)
	{
		map <int,int> mp;
		now*=2;now++;
		int cnt1=0;
		for(int i=0;i<n;i++)mp[(a[i]>>t)]++;
		for(auto u:mp)if(((u.first)^now)>u.first)cnt1+=mp[((u.first)^now)]*u.second;
		if(cnt1<m)now--,m-=cnt1;
	}
	long long ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if((a[i]^a[j])>now)
				ans+=(a[i]^a[j]),m2--;
	ans+=1LL*m2*now;ans%=MOD;
	cout<<ans;
	return 0;
}