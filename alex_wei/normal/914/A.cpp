#include<bits/stdc++.h>
using namespace std;
int n,a,ans=-1e6;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==0)continue;
		if(a<0)ans=max(ans,a);
		else{
			int k=sqrt(a);
			if(k*k!=a)ans=max(ans,a);
		}
	}
	cout<<ans;
	return 0;
}