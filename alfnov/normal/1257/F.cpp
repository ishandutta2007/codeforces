#include<bits/stdc++.h>
using namespace std;
int a[105],f[105],g[105],l[105],pc[1<<15];
unsigned long long mo=111339248186143ull,bs[105];
map<unsigned long long,int>mp;
int main()
{
	for(int i=1;i<(1<<15);i++)pc[i]=pc[i^(i&-i)]+1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=a[i]>>15,g[i]=a[i]&((1<<15)-1);
	}
	bs[0]=1;
	for(int i=1;i<=n;i++)bs[i]=bs[i-1]*mo;
	unsigned long long he=0;
	for(int i=0;i<n;i++)he+=bs[i];
	for(int i=0;i<(1<<15);i++)
	{
		for(int j=1;j<=n;j++)l[j]=pc[i^g[j]];
		unsigned long long mm=0;
		for(int j=1;j<=n;j++)mm=mm*mo+l[j];
		mp[mm]=i+1;
	}
	for(int i=0;i<(1<<15);i++)
	{
		int mx=0;
		for(int j=1;j<=n;j++)
			l[j]=pc[i^f[j]],mx=max(mx,l[j]);
		unsigned long long mm=0;
		for(int j=1;j<=n;j++)mm=mm*mo+(mx-l[j]);
		for(int j=mx;j<=30;j++)
		{
			if(mp[mm])
			{
				cout<<(i<<15)+(mp[mm]-1)<<endl;
				return 0;
			}
			mm+=he;
		}
	}
	cout<<-1<<endl;
	return 0;
}