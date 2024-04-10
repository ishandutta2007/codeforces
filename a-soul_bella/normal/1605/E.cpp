#include <bits/stdc++.h>
#define int long long
using namespace std;
int mu[2000005],a[2000005],b[2000005],c[2000005],ans[2000005],cfi[2000005],cf1[2000005];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	mu[1]=1;
	for(int i=1;i<=2000000;i++)
		for(int j=i+i;j<=2000000;j+=i)
			mu[j]-=mu[i];
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		cin >> b[i];
	b[1]=0;
	for(int i=1;i<=n;i++)
		b[i]-=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+i;j<=n;j+=i)
			b[j]-=b[i];
		c[i]=b[i];
		b[i]=0;
	}
	int cnt=0,Sum=0;
	for(int i=1;i<=n;i++)
	{
		if(mu[i]==-1) c[i]*=-1;
		if(mu[i]==0) Sum+=max(c[i],-c[i]);
		if(mu[i]) c[++cnt]=c[i]; 
	}
	swap(cnt,n);
	sort(c+1,c+n+1);
	int q;
	cin >> q;
	for(int i=1;i<=n;i++)
	{
		if(c[i]<0)
		{
			cf1[0]-=c[i];
			cfi[0]-=1;
			if(-c[i]<=1000000)
			{
				cf1[-c[i]]+=c[i]+c[i];
				cfi[-c[i]]+=2;
			}
		}
		else
		{
			cf1[0]+=c[i];
			cfi[0]++;
		}
	}
	for(int i=1;i<=2000000;i++)
	{
		cf1[i]+=cf1[i-1],cfi[i]+=cfi[i-1];
	}
	while(q--)
	{
		int x;
		cin >> x;
		cout << cf1[x]+cfi[x]*x+Sum << "\n";
	}
	return 0;
}
/*
2
1 1000000
1 1
2
1
1000000
*/