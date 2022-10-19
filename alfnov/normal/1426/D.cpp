#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long b[200005],bb[200005];
vector<int>v[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=b[i-1]+a[i];
	for(int i=0;i<=n;i++)bb[i]=b[i];
	sort(bb,bb+n+1);
	for(int i=0;i<=n;i++)b[i]=lower_bound(bb,bb+n+1,b[i])-bb;
	for(int i=0;i<=n;i++)v[b[i]].push_back(i);
	int la=0,ans=0;
	for(int i=0;i<=n;i++)
	{
		int wz=lower_bound(v[b[i]].begin(),v[b[i]].end(),i)-v[b[i]].begin();
		if(wz!=0&&v[b[i]][wz-1]>=la-1)
		{
			ans++;
			la=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}