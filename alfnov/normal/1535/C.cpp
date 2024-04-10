#include<bits/stdc++.h>
using namespace std;
char s[200005];
int a[200005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')a[i]=-1;
			else a[i]=(i+(s[i]-'0'))&1;
		}
		long long ans=0;
		for(int k=-1;k<2;k++)
		{
			int wz=0;
			while(wz<=n)
			{
				int dd=wz;
				while(wz<n&&(a[wz+1]==-1||a[wz+1]==k))wz++;
				ans+=(k==-1?-1:1)*1ll*(wz-dd)*(wz-dd+1)/2;
				wz++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}