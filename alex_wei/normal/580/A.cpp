#include<bits/stdc++.h>
using namespace std;
int n,a,c,ans,b; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		if(b>=a)c++;
		else ans=max(ans,c),c=1;
		a=b;
	}
	cout<<max(ans,c);
    return 0;
}