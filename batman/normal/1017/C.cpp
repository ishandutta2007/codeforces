#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)

ll n,ans,res;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n==1)return cout<<"1\n",0;
	ans=N;
	for(int i=1;i<=n;i++)
		if(i+(n+i-1)/i<ans)
			ans=i+(n+i-1)/i,
			res=i;
	int now=1;
	for(int p=0;p<n%res;p++)
	{
		int sz=(n+res-1)/res;
		for(int i=now+sz-1;i>=now;i--)cout<<i<<" ";
		now+=sz;
	}
	for(int p=0;p<res-n%res;p++)
	{
		int sz=n/res;
		for(int i=now+sz-1;i>=now;i--)cout<<i<<" ";
		now+=sz;
	}
	cout<<"\n";
	return 0;
}