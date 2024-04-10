#include<bits/stdc++.h>
using namespace std;
int n,h[102],m=1000,s,t;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++){
		int j=i+1;
		if(j>n)j=1;
		if(abs(h[i]-h[j])<m)
			m=abs(h[i]-h[j]),s=i,t=j;
	}
	cout<<s<<" "<<t;
	return 0;
}