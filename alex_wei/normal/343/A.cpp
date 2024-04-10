#include<bits/stdc++.h>
long long a,b,c,ans; 
int main()
{
	std::cin>>a>>b;
	while(b!=0)ans+=a/b,c=a%b,a=b,b=c;
	std::cout<<ans;
}