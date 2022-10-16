#include<bits/stdc++.h>
using namespace std;
long long n,q,a[200002],mx[200002],ans,p[200002],x[200002],g[200002];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>g[i];
		if(g[i]==1)cin>>p[i]>>x[i];
		else cin>>x[i];
	}
	for(int i=q;i>0;i--)
		g[i]==2?ans=max(ans,x[i]):mx[i]=max(ans,x[i]);
	for(int i=1;i<=n;i++)
		if(a[i]<ans)a[i]=ans;
	for(int i=1;i<=q;i++)
		if(g[i]==1)
			a[p[i]]=mx[i];
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}