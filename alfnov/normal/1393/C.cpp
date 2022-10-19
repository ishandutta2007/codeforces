#include<bits/stdc++.h>
using namespace std;
int a[100005],gs[100005],d[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,mxx=0;
		cin>>n;
		for(int i=1;i<=n;i++)gs[i]=d[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),gs[a[i]]++;
		for(int i=1;i<=n;i++)d[gs[i]]++;
		for(int i=1;i<=n;i++)if(d[i])mxx=i;
		cout<<(n-d[mxx]+1-mxx)/(mxx-1)<<endl;
	}
	return 0;
}