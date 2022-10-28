#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, sum=0, ans=1e15;
int a[N], f[5], curf[5], havef[5];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
		sum+=a[i];
	}
	for(int fours=0;fours*4<=sum;fours++)
	{
		if((sum-(fours*4))%3!=0)
			continue;
		curf[4]=fours;
		curf[3]=(sum-(fours*4))/3;
		curf[0]=n-curf[4]-curf[3];
		for(int j=0;j<=4;j++)
			havef[j]=f[j];
		int curans=0, diff=0;
		int i=4, j=4;
		while(i>=0 && j>=0)
		{
			int take=min(curf[i], havef[j]);
			curf[i]-=take;
			havef[j]-=take;
			diff+=take*abs(i-j);
			if(curf[i]==0)
				i--;
			if(havef[j]==0)
				j--;
		}	
		curans=diff/2;
		ans=min(ans, curans);
	}
	if(ans==1e15)
		ans=-1;
	cout<<ans;
	return 0;
}