#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int a,b;
	bool operator<(const apple &other)const
	{
		return a<other.a;
	}
}f[100005];
long long z[100005],l[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;i++)scanf("%d%d",&f[i].a,&f[i].b);
		sort(f+1,f+m+1);
		z[m+1]=0;
		for(int i=m;i>=1;i--)z[i]=z[i+1]+(l[i]=f[i].a);
		long long ans=0;
		for(int i=1;i<=m;i++)
		{
			int wz=upper_bound(l+1,l+m+1,f[i].b)-l;
			int gs=m-wz+1;
			if(f[i].a>f[i].b)gs--;
			if(n<=gs)gs=n-1;
			long long anss=f[i].a+1ll*(n-gs-1)*f[i].b;
			wz=m-gs+1;
			int flag=0;
			if(i>=wz)wz--,flag=1;
			anss+=z[wz]-flag*f[i].a;
			ans=max(ans,anss);
		}
		cout<<ans<<endl;
	}
	return 0;
}