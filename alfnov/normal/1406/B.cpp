#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0)
			{
				flag=1;
				n--,i--;
			}
		}
		sort(a+1,a+n+1);
		int wz=n+1;
		for(int i=n;i>=1;i--)if(a[i]>0)wz=i;
		long long ans=LLONG_MIN;
		if(flag)ans=0;
		if(n-wz+1>=5)ans=max(ans,1ll*a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]);
		if(wz>1&&n-wz+1>=4)ans=max(ans,1ll*a[wz-1]*a[wz]*a[wz+1]*a[wz+2]*a[wz+3]);
		if(wz>2&&n-wz+1>=3)ans=max(ans,1ll*a[1]*a[2]*a[n]*a[n-1]*a[n-2]);
		if(wz>3&&n-wz+1>=2)ans=max(ans,1ll*a[wz-1]*a[wz-2]*a[wz-3]*a[wz]*a[wz+1]);
		if(wz>4&&n-wz+1>=1)ans=max(ans,1ll*a[1]*a[2]*a[3]*a[4]*a[n]);
		if(wz>5)ans=max(ans,1ll*a[wz-1]*a[wz-2]*a[wz-3]*a[wz-4]*a[wz-5]);
		cout<<ans<<endl;
	}
	return 0;
}