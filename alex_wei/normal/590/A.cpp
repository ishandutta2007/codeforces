#include<bits/stdc++.h>
using namespace std;
int n,a[500002],ans,m[500002],p;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;){
		if(i==1||i==n||a[i]==a[i-1]||a[i]==a[i+1]){m[++p]=a[i++];continue;}
		int pos=i+1,c;
		while(pos<n&&a[pos]!=a[pos-1]&&a[pos]!=a[pos+1])pos++;
		c=(pos-i+1)/2,ans=max(ans,c);
		if(a[i-1]==a[pos])for(int j=i;j<=pos;j++)m[++p]=a[i-1];
		else for(int j=i;j<=pos;j++)m[++p]=j-i<c?a[i-1]:a[pos];
		i=pos+1;
	}
	cout<<ans<<endl;
	for(int i=1;i<=p;i++)cout<<m[i]<<" ";
	return 0;
}