#include <iostream>
#include <algorithm>
using namespace std;
int n,k,x,y,a[200005],b[200005],ans[200005];
int main()
{
	int i;
	cin>>n>>k;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i];
	 	b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++) ans[i]=lower_bound(b+1,b+n+1,a[i])-b-1;
	while(k--)
	{
		cin>>x>>y;
		if(a[x]<a[y]) ans[y]--;
		else if(a[y]<a[x]) ans[x]--;
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}