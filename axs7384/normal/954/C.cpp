#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,a[200005],ans;
int main()
{
	ans=inf;
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<n;++i)
		if (abs(a[i]-a[i+1])>1)
		{
			if (ans!=inf&&ans!=abs(a[i]-a[i+1]))
			{
				puts("NO");
			    return 0;
			}
			ans=abs(a[i]-a[i+1]);
		}
		else 
		{
			if (a[i]==a[i+1])
			{
				puts("NO"); 
				return 0;
			}
		}
	for (int i=1;i<n;++i)
		if (abs(a[i]-a[i+1])==1&&(a[i]-1)/ans!=(a[i+1]-1)/ans)
		{
			puts("NO"); 
			return 0;
		}
	puts("YES");
	cout<<"1000000000 "<<ans;
}