#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,a,b,n;
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>n;
		if(n%3==0)cout<<a<<endl;
		else if(n%3==1)cout<<b<<endl;
		else if(n%3==2)cout<<(a^b)<<endl;
	}
	return 0; 
}