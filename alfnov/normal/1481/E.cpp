#include<bits/stdc++.h>
using namespace std;
vector<int>g[500005];
int a[500005],f[500005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),g[a[i]].push_back(i);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(g[a[i]].back()==i)f[i]=max(f[i],f[g[a[i]][0]-1]+(int)g[a[i]].size());
	}
	int m=f[n];
	for(int i=1;i<n;i++)
	{
		int wz=lower_bound(g[a[i+1]].begin(),g[a[i+1]].end(),i+1)-g[a[i+1]].begin();
		m=max(m,(int)g[a[i+1]].size()-wz+f[i]);
	}
	cout<<n-m<<endl;
	return 0;
}