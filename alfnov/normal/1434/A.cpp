#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int h,l,z;
	bool operator<(const apple &other)const
	{
		if(z==other.z&&h==other.h)return l<other.l;
		if(z==other.z)return h<other.h;
		return z<other.z;
	}
	apple(int h=0,int l=0,int z=0):h(h),l(l),z(z){}
}e[1000005];
int a[105],b[100005],vist[100005];
int main()
{
	for(int i=1;i<=6;i++)scanf("%d",&a[i]);
	sort(a+1,a+7);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	int tot=0;
	for(int i=1;i<=6;i++)for(int j=1;j<=n;j++)
		e[++tot]=apple(i,j,b[j]-a[i]);
	sort(e+1,e+tot+1);
	int ans=INT_MAX;
	int r=0,al=0;
	for(int i=1;i<=tot;i++)
	{
		for(;r<=tot;)
		{
			if(al==n)break;
			r++;
			if(r>tot)break;
			vist[e[r].l]++;
			if(vist[e[r].l]==1)al++;
		}
		if(al!=n)continue;
		ans=min(ans,e[r].z-e[i].z);
		vist[e[i].l]--;
		if(!vist[e[i].l])al--;
	}
	cout<<ans<<endl;
	return 0;
}