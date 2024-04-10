#include<bits/stdc++.h>
using namespace std;
int z,f,n,a;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>0)z++;
		if(a<0)f++;
	}
	if(2*z>=n)cout<<1;
	else if(2*f>=n)cout<<-1;
	else cout<<0;
	return 0;
}