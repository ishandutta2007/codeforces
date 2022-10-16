#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans=1,c;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		c+=a;
		if(c>m)ans++,c=a;
	}
	cout<<ans;
	return 0;
}