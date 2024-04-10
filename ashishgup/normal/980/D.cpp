#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5e3+5;

int n, ctr=1;
int a[N], ans[N], f[N];
map<int, int> compress;

inline int get(int k)
{
	if(k==0)
		return k;
	int neg=(k<0);
	k=abs(k);
	int num=1;
	int storek=k;
	for(int i=2;i*i<=storek;i++)
	{
		int ct=0;
		while(k%i==0)
		{
			ct++;
			k/=i;
		}
		if(ct%2)
			num*=i;
	}
	num*=k;
	num*=(neg==1?-1:1);
	return num;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=get(a[i]);
		if(a[i])
			compress[a[i]];
	}	
	for(auto &it:compress)
	{
		it.second=ctr++;
	}
	for(int i=1;i<=n;i++)
		a[i]=compress[a[i]];
	for(int i=1;i<=n;i++)
	{
		memset(f, 0, sizeof(f));
		int zeros=0, distinct=0;
		for(int j=i;j<=n;j++)
		{
			f[a[j]]++;
			if(f[a[j]]==1)
			{
				distinct++;
				if(a[j]==0)
				{
					zeros++;
					distinct--;
				}
			}
			int curans=distinct;
			if(distinct==0)
				curans+=(zeros>0);
			ans[curans]++;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}