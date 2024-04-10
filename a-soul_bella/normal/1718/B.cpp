#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],f[1000],del[1005],n,lstd[1005],A[1005];
int pos=-1;
bool check()
{
	for(int i=0;i<=pos;i++) lstd[i]=del[i];
	for(int i=1;i<=n;i++) A[i]=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=pos;j>=0;j--)
		{
			if(!del[j]&&del[j+1]!=i&&(j==0||del[j-1]!=i)&&a[i]>=f[j])
			{
				del[j]=i,a[i]-=f[j];
			}
		}
		if(a[i])
		{
			for(int i=0;i<=pos+1;i++) del[i]=0;
			for(int i=1;i<=n;i++) a[i]=A[i];
			return 0;
		}
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0]=f[1]=1;
	for(int i=2;i<=80;i++) f[i]=f[i-1]+f[i-2];
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		int S=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			S+=a[i];
		}
		pos=-1;
		for(int i=0;i<=80;i++)
		{
			if(S<=f[i])
			{
				if(S==f[i])pos=i;
				break;
			}
			S-=f[i]; 
		}
		if(pos==-1)
		{
			cout << "NO\n";
			continue;
		}
		for(int i=0;i<=pos+1;i++) del[i]=0;
		sort(a+1,a+n+1);reverse(a+1,a+n+1); 
		if(check()) cout << "YES\n";
		else
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				int lst=a[i];
				del[0]=i;
				--a[i];
				if(check()) flag=1;
				++a[i],del[0]=0;
				if(flag) break;
			}
			if(flag) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
/*
1
3
11 5 4
*/