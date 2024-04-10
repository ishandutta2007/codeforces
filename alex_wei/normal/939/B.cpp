#include<bits/stdc++.h>
using namespace std;
long long n,k,c=1e18,m,t,s;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>t;
		if(n%t<=c)c=n%t,m=i,s=n/t;
	}
	cout<<m<<" "<<s;
    return 0;
}