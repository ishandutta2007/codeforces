#include<bits/stdc++.h>
using namespace std;
int n,b,d,a,now,ans; 
int main()
{
	cin>>n>>b>>d;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>b)continue;
		now+=a;
		if(now>d)now=0,ans++;
	}
	cout<<ans;
	return 0;
}