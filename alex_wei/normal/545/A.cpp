#include<bits/stdc++.h>
using namespace std;
int n,a,k[102],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>a;
			if(a==1)k[i]=1;
			if(a==2)k[j]=1;
			if(a==3)k[i]=k[j]=1;
		}
	for(int i=1;i<=n;i++)
		ans+=!k[i];
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(!k[i])cout<<i<<" ";
	return 0;
}